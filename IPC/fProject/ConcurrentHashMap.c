#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif
#include "HashMap.h"
#include "bucket.h"
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

#define OK   1   
#define MAGIC 1073741824
#define MININPUT 1
#define IS_INVALID(H) ((NULL == (H)) || (H)->m_magic != MAGIC)


typedef struct Lock_t
{
	pthread_mutex_t m_lock;
	int m_isFree;
}Lock_t;

struct HashMap
{
	size_t m_magic; 
    Bucket_t** m_items;			    	/*data holder*/
	size_t m_size;			            /*actual DS size*/
	size_t m_noItems;		            /*number of inputs*/
    Lock_t* m_myMutexPool;				/*pool of lockes */
	size_t m_nMutexes;					/*number of mutexes in inventory */
    HashFunction m_hashFunc;            /*Hash func given by client*/
	EqualityFunction m_keysEqualFunc; 	/* Equality Function given by client*/

};



static size_t GetNumber(size_t _number);			/*next prime number*/
static void Hash_Mutex_Pool_Init(size_t _nThread,Lock_t **_myMutexPool,size_t *_size);
static void Hash_Init(HashMap* _map,size_t _primeN, HashFunction _hashFunc, EqualityFunction _keysEqualFunc);
static Map_Result ReHashLoop(HashMap *_map,Bucket_t** _oldHash,size_t _hashOldSize);
static size_t HashIdx(HashMap* _map,const void* _key);
static size_t HashMutexIdx(HashMap* _map,size_t _idx);




/** 
 * @brief Create a new hash map with given capcity and key characteristics.
 * @param[in] _capacity - Expected max capacity 
 * 						  shall be rounded to nearest larger prime number.
 * @param[in] _hashFunc - hashing function for keys
 * @param[in] _keysEqualFunc - equality check function for keys. 
 * @return newly created map or null on failure
 */
HashMap* HashMap_Create(size_t _capacity, size_t _nThread, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
    HashMap *hash;
	size_t primeN; 
	
	/*parameter check*/
	if(_capacity <= MININPUT || !_hashFunc || !_keysEqualFunc || !_nThread)
	{
		return NULL;
	}
	hash = (HashMap*)calloc(1,sizeof(HashMap));
    if(!hash)
	{
		return NULL;
	}
	/*real capacity*/
	primeN = GetNumber(_capacity);
    hash->m_items = (Bucket_t**)calloc(primeN,sizeof(Bucket_t*));
	if(!(hash->m_items))
	{
		free(hash);
		return NULL;
	}
	Hash_Mutex_Pool_Init(_nThread ,&(hash->m_myMutexPool),&(hash->m_nMutexes));
	if(!(hash->m_myMutexPool))
	{
		free(hash->m_items);
		free(hash);
		return NULL;
	}
    Hash_Init(hash,primeN,_hashFunc,_keysEqualFunc);
	return hash;
}
/*
static Bucket_Destroy()
*/
/**
 * @brief destroy hash map and set *_map to null
 * @param[in] _map : map to be destroyed
 * @param[optional] _keyDestroy : pointer to functionto destroy keys
 * @param[optional] _valDestroy : pointer to functionto destroy values 
 * @details optionally destroy all keys and values using user provided functions
 */
void HashMap_Destroy(HashMap** _map, void (*_keyDestroy)(void* _key), void (*_valDestroy)(void* _value))
{
	size_t mapSize;
	int i;


	if(!_map || IS_INVALID(*_map))
	{
		return;
	}
	(*_map)->m_magic = 0;
	mapSize = (*_map)->m_size;
	
	for(i = 0;i < mapSize;++i)
	{
		Bucket_Destroy((*_map)->m_items[i],_keyDestroy,_valDestroy);
	}
	for(i = 0;i < (*_map)->m_nMutexes; ++i)
	{
		pthread_mutex_destroy(&((*_map)->m_myMutexPool[i].m_lock));
	}
	free((*_map)->m_items);
	free(*_map);
}


/**
 * @brief Get number of key-value pairs inserted into the hash map
 * @warning complexity can be O(?)
 */

size_t HashMap_Size(const HashMap* _map)
{
	if(IS_INVALID(_map))
	{
		return 0 ;
	}
	return _map->m_noItems;
}




/** 
 * @brief Insert a key-value pair into the hash map.
 * @param[in] _map - Hash map adt to insert to, must be initialized
 * @param[in] _key - key to serve as index 
 * @param[in] _value - The value to associate with the key 
 * @return Success indicator
 * @retval  MAP_SUCCESS	on success
 * @retval  MAP_KEY_DUPLICATE_ERROR	if key allread present in the map
 * @retval  MAP_KEY_NULL_ERROR
 * @retval  MAP_ALLOCATION_ERROR on failure to allocate key-value pair
 * @retval  MAP_UNINITIALIZED_ERROR
 * 
 * @warning key must be unique and destinct
 */
Map_Result HashMap_Insert(HashMap* _map, void* _key, void* _value)
{
	size_t idx;
	int error;
	size_t mutexIdx;
	Lock_t* mutexPtr;

	if(IS_INVALID(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if(!_key)
	{
		return MAP_KEY_NULL_ERROR;
	}
	
	idx = HashIdx(_map,_key);
	mutexIdx = HashMutexIdx(_map,idx);
	mutexPtr = &(_map->m_myMutexPool[mutexIdx]);
	pthread_mutex_lock(&(mutexPtr->m_lock));

	
	error = Bucket_Insert(_key,_value,&(_map->m_items[idx]),_map->m_keysEqualFunc);

	++_map->m_noItems;
	pthread_mutex_unlock(&(mutexPtr->m_lock));

	return error;
}

/** 
 * @brief Remove a key-value pair from the hash map.
 * @param[in] _map - Hash map to remove pair from, must be initialized
 * @param[in] _key - key to serve as index to locate _value
 * @param[in] _pValue - pointer to variable that will get the value if found.
 * @return Success indicator
 * @retval  MAP_SUCCESS	on success
 * @retval  MAP_KEY_NULL_ERROR
 * @retval  MAP_KEY_NOT_FOUND_ERROR if key not found
 * @retval  MAP_UNINITIALIZED_ERROR
 * 
 * @warning key must be unique and destinct
 */
Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, void** _pValue)
{
	size_t idx;
	int error = -1;
	size_t mutexIdx;
	Lock_t* mutexPtr;
	

	if(IS_INVALID(_map) || !_pValue)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if(!_searchKey)
	{
		return MAP_KEY_NULL_ERROR;
	}

	idx = HashIdx(_map,_searchKey);
	mutexIdx = HashMutexIdx(_map,idx);
	mutexPtr = &(_map->m_myMutexPool[mutexIdx]);
	pthread_mutex_lock(&(mutexPtr->m_lock));


	error = Bucket_Remove(_map->m_items[idx],_searchKey,_pValue);
	if(error == MAP_SUCCESS)
		--_map->m_noItems;

	pthread_mutex_unlock(&(mutexPtr->m_lock));

	return error;
}

static void Lock_All(Lock_t* _lockPool,size_t _nLocks)
{
	int i;
	
	for(i = 0; i < _nLocks; ++i)
	{
		pthread_mutex_lock(&(_lockPool[i].m_lock));
	} 
}

static void UnLock_All(Lock_t* _lockPool,size_t _nLocks)
{
	int i;
	
	for(i = 0; i < _nLocks; ++i)
	{
		pthread_mutex_unlock(&(_lockPool[i].m_lock));
	} 
}
/** 
 * @brief Adjust map capacity and rehash all key/value pairs
 * @param[in] _map - existing map
 * @param[in] _newCapacity - new capacity shall be rounded to nearest larger prime number.
 * @return MAP_SUCCESS or MAP_ALLOCATION_ERROR
 */
Map_Result HashMap_Rehash(HashMap *_map, size_t _newCapacity)
{
    Bucket_t** oldHash = NULL;
	size_t hashOldSize,newPrimeCapacity,nItems;
	Map_Result error;

	if(IS_INVALID(_map) || !_newCapacity)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	Lock_All(_map->m_myMutexPool,_map->m_nMutexes);
	nItems = _map->m_noItems; /**<-because  im using insert func that update noItems */
	hashOldSize = _map->m_size;
	oldHash = _map->m_items;
	newPrimeCapacity = GetNumber(_newCapacity);
    _map->m_items = (Bucket_t**)calloc(newPrimeCapacity,sizeof(Bucket_t*));
    if(!(_map->m_items))
    {
		_map->m_items = oldHash;
  		return MAP_ALLOCATION_ERROR;
    }
	_map->m_size = newPrimeCapacity;
	error = ReHashLoop(_map,oldHash,hashOldSize);
    _map->m_noItems = nItems; 
	UnLock_All(_map->m_myMutexPool,_map->m_nMutexes);
	return error;
}

static Map_Result ReHashLoop(HashMap *_map,Bucket_t** _oldHash,size_t _hashOldSize)
{
	int i,j;
	void *dataHolder = NULL,*key = NULL;
	size_t _oldBucketSize,newBucketidx;


	for(i = 0; i < _hashOldSize; ++i)
    {
		if((_oldBucketSize = Bucket_Size(_oldHash[i])))
		{
			for(j = 0;j < _oldBucketSize; ++j)
			{
				key = Bucket_Get_First_Key(_oldHash[i]);
				assert(key);
				assert(Bucket_Remove(_oldHash[i],key,&dataHolder) == MAP_SUCCESS);
				assert(dataHolder);
				newBucketidx = HashIdx(_map,key);
				assert(Bucket_Insert(key,dataHolder,&(_map->m_items[newBucketidx]),_map->m_keysEqualFunc) == MAP_SUCCESS);
			}
			Bucket_Destroy(_oldHash[i],NULL,NULL);
		}
	}
	return MAP_SUCCESS;
}
  
/** 
 * @brief Find a value by key
 * @param[in] _map - Hash map to remove pair from, must be initialized
 * @param[in] _key - key to serve as index 
 * @param[in] _pValue - pointer to variable that will get the value if found.
 * @return Success indicator
 * @retval  MAP_SUCCESS	on success
 * @retval  MAP_KEY_NULL_ERROR
 * @retval  MAP_KEY_NOT_FOUND_ERROR if key not found
 * @retval  MAP_UNINITIALIZED_ERROR
 * 
 * @warning key must be unique and destinct
 */
Map_Result HashMap_Find(const HashMap* _map, const void* _key, void** _pValue)
{
	size_t idx;
	Map_Result error;
	size_t mutexIdx;
	Lock_t* mutexPtr;
	
	

	if(IS_INVALID(_map) || !_pValue)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if(NULL == _key)
	{
		return MAP_KEY_NULL_ERROR;
	}
	idx = HashIdx((HashMap*)_map,_key);
	mutexIdx = HashMutexIdx((HashMap*)_map,idx);
	mutexPtr = &(_map->m_myMutexPool[mutexIdx]);
	pthread_mutex_lock(&(mutexPtr->m_lock));

	error = Bucket_Find(_map->m_items[idx],_key,_pValue);

	pthread_mutex_unlock(&(mutexPtr->m_lock));
	return error;
}



/** 
 * This method is optional in the homework 
 * @brief Iterate over all key-value pairs in the map.
 *                   Iteration will stop if _act returns a zero for a given pair
 * @details The user provided KeyValueActionFunction _action will be called for each element.  
 * @param[in] _map - Hash map to iterate over.
 * @param[in] _act - User provided function pointer to be invoked for each element
 * @returns number of times the user functions was invoked
 */
size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	
	size_t count = 0, size;
	int i;

	if(IS_INVALID(_map) || !_action)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	size = _map->m_size;
	for(i = 0; i < size; ++i)
    {
		count += Bucket_ForEach(_map->m_items[i],_action,_context);
	}
	return count;
}


static size_t HashIdx(HashMap* _map,const void* _key)
{
	return (_map->m_hashFunc(_key))%_map->m_size;
}



static size_t IsPrime(size_t _n)
{
    int i;

    if (_n <= 1) return 0;
    if (_n <= 3) return 1;
    if (_n%2 == 0 || _n%3 == 0) return 0;
    for (i = 5; i*i <= _n; i = i+6)
        if (_n%i == 0 || _n%(i+2) == 0)
           return 0;
    return 1;
}

static size_t GetNumber(size_t _number)
{
	while (1)
    {
        if (IsPrime(_number)) break;
        ++_number;
    }
    return _number;
}

static size_t HashMutexIdx(HashMap* _map,size_t _idx)
{
	return _idx % _map->m_nMutexes;
}


static void Hash_Mutex_Pool_Init(size_t _nThread,Lock_t **_myMutexPool,size_t *_size)
{
	int i;
	
	
	*_myMutexPool = malloc(_nThread*sizeof(Lock_t)); 
	if(!(*_myMutexPool))
		return;

	for (i = 0; i < _nThread;++i)
	{
		if(pthread_mutex_init(&((*_myMutexPool)[i].m_lock),NULL))
		{
			break;	
		}
		(*_myMutexPool)[i].m_isFree = 1;
	}
	*_size = i;
	if(i < (_nThread - 1))
	{
		*_myMutexPool = realloc(*_myMutexPool,i*sizeof(Lock_t));
	}

}

static void Hash_Init(HashMap* _map,size_t _primeN, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
	
	_map->m_size = _primeN;
	_map->m_noItems = 0;
	_map->m_hashFunc = _hashFunc;
	_map->m_keysEqualFunc = _keysEqualFunc;
	_map->m_magic = MAGIC;	
}

#ifndef NDEBUG


Map_Stats HashMap_GetStatistics(const HashMap* _map)
{
	Map_Stats stats = {0};
	size_t size;
	int cur = 0,count_max = 0, i;

	if(IS_INVALID(_map))
	{
		return stats;
	}
	size = _map->m_size;
	stats.numberOfBuckets = _map->m_size;
	for(i = 0;i < size;++i)
	{
		cur = Bucket_Size(_map->m_items[i]);
		if(cur != 0)
		{
			++(stats.numberOfChains);
			if (cur > count_max)
			{
				count_max = cur;
			}
		}
	}
	stats.maxChainLength = count_max;
	stats.averageChainLength = (_map->m_noItems)/(stats.numberOfChains);
	return stats;
	
}
#endif /* NDEBUG */


