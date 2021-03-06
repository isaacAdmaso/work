#include "HashMap.h"
#include "list_functions.h"
#include <stdlib.h>
#include <assert.h>

#define OK   1   
#define MAGIC 1073741824
#define MININPUT 1
#define IS_INVALID(H) ((NULL == (H)) || (H)->m_magic != MAGIC)


struct HashMap
{
	size_t m_magic; 
    List** m_items;			                /*data holder*/
	size_t m_size;			                /*actual DS size*/
	size_t m_noItems;		                /* number of inputs*/
    HashFunction m_hashFunc;                /*Hash func given by client*/
    EqualityFunction m_keysEqualFunc;        /* Equality Function given by client*/
};

typedef struct pair
{
	void* m_key;
	void* m_data;
}pair;

typedef struct Destroy_Pair_Func
	{
		Destroy m_keyDestroy; 
		Destroy m_valDestroy;
	}Destroy_Pair_Func;

static size_t GetNumber(size_t _number);/*next prime number*/

static void Hash_Init(HashMap* _map,size_t _primeN, HashFunction _hashFunc, EqualityFunction _keysEqualFunc);
/** 
 * @brief Create a new hash map with given capcity and key characteristics.
 * @param[in] _capacity - Expected max capacity 
 * 						  shall be rounded to nearest larger prime number.
 * @param[in] _hashFunc - hashing function for keys
 * @param[in] _keysEqualFunc - equality check function for keys. 
 * @return newly created map or null on failure
 */
HashMap* HashMap_Create(size_t _capacity, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
    HashMap *h;
	size_t primeN; 
	
	/*parameter check*/
	if(_capacity <= MININPUT || NULL == _hashFunc || NULL == _keysEqualFunc)
	{
		return NULL;
	}
	h = (HashMap*)malloc(sizeof(HashMap));
    if(NULL == h)
	{
		return NULL;
	}
	/*real capacity*/
	primeN = GetNumber(_capacity);
    h->m_items =(List**)malloc(primeN*sizeof(List*));
	if(NULL == h->m_items)
	{
		free(h);
		return NULL;
	}
    Hash_Init(h,primeN,_hashFunc,_keysEqualFunc);
	return h;
}

static size_t HashIdx(HashMap* _map,pair* _data)
{
	return (_map->m_hashFunc(_data->m_key))%_map->m_size;
}

static int Destroy_Pair(void* _element, void* _destryStruct)
{
	pair* nodeData = _element;
	Destroy_Pair_Func* d_p_f = (Destroy_Pair_Func*)_destryStruct;

	if(NULL == nodeData)
	{
		return 0;/**is NULL data allowed? */
	}
	d_p_f->m_keyDestroy(nodeData->m_key);
	d_p_f->m_valDestroy(nodeData->m_data);
	return OK;
}
static void Free_Pair(void* _pair)
{
	if(_pair != NULL)
		free(_pair);
}
/**
 * @brief destroy hash map and set *_map to null
 * @param[in] _map : map to be destroyed
 * @param[optional] _keyDestroy : pointer to functionto destroy keys
 * @param[optional] _valDestroy : pointer to functionto destroy values 
 * @details optionally destroy all keys and values using user provided functions
 */
void HashMap_Destroy(HashMap** _map, void (*_keyDestroy)(void* _key), void (*_valDestroy)(void* _value))
{
	Destroy_Pair_Func d_p_f;
	size_t mapSize;
	int i;
	ListItr start,end;


	if(NULL == _map || IS_INVALID(*_map))
	{
		return;
	}
	(*_map)->m_magic = 0;
	mapSize = (*_map)->m_size;
	d_p_f.m_keyDestroy = _keyDestroy;
	d_p_f.m_valDestroy = _valDestroy;
	
	for(i = 0;i < mapSize;++i)
	{
		if(NULL != _keyDestroy && NULL != _valDestroy)
		{
			start = ListItr_Begin((*_map)->m_items[i]);
			end = ListItr_End((*_map)->m_items[i]);
			ListItr_ForEach(start,end,Destroy_Pair,&d_p_f);
		}
		/*pair destroy*/
		List_Destroy(&((*_map)->m_items[i]),Free_Pair);
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
Map_Result HashMap_Insert(HashMap* _map, const void* _key, const void* _value)
{
	pair *data,*checkData;
	size_t idx;
	ListItr begin, end;
	

	if(IS_INVALID(_map))
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if(NULL == _key)
	{
		return MAP_KEY_NULL_ERROR;
	}

	if(!(data = (pair*)malloc(sizeof(pair))))
	{
		return MAP_ALLOCATION_ERROR;
	}
	data->m_key = (void*)_key;
	data->m_data = (void*)_value;
	
	idx = HashIdx(_map,data);
	begin = ListItr_Begin(_map->m_items[idx]);
	end = ListItr_End(_map->m_items[idx]);
	if(NULL == begin)
	{
		_map->m_items[idx] = List_Create();
		if(NULL == _map->m_items[idx])
		{
			return MAP_ALLOCATION_ERROR;
		}
	}
	for(;begin != end ;begin = ListItr_Next(begin))
	{
		checkData = ListItr_Get(begin);
		if(_map->m_keysEqualFunc(checkData->m_key,data->m_key))
		{
			free(data);
			return MAP_KEY_DUPLICATE_ERROR;
		}
	}

	List_PushTail(_map->m_items[idx],(void*)data);
	++_map->m_noItems;
	return MAP_SUCCESS;
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
	pair data  ,*checkData;
	size_t idx;
	ListItr begin, end;

	if(IS_INVALID(_map) || NULL ==  _pValue)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if(NULL == _searchKey)
	{
		return MAP_KEY_NULL_ERROR;
	}
	data.m_key = (void*)_searchKey;
	idx = HashIdx(_map,&data);
	begin = ListItr_Begin(_map->m_items[idx]);
	end = ListItr_End(_map->m_items[idx]);

	for(;begin != end ;begin = ListItr_Next(begin))
	{
		checkData = ListItr_Get(begin);
		if(_map->m_keysEqualFunc(checkData->m_key,data.m_key))
		{
			checkData = (pair*)ListItr_Remove(begin);
			*_pValue = checkData->m_data;
			--_map->m_noItems;
			return MAP_SUCCESS;
		}
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}
/** 
 * @brief Adjust map capacity and rehash all key/value pairs
 * @param[in] _map - exisiting map
 * @param[in] _newCapacity - new capacity shall be rounded to nearest larger prime number.
 * @return MAP_SUCCESS or MAP_ALLOCATION_ERROR
 */
Map_Result HashMap_Rehash(HashMap *_map, size_t newCapacity)
{
	int i;
	pair* dataHlder;
	ListItr begin, end,cur;
    List** m_NewData = NULL;
    size_t old_size;

	if(IS_INVALID(_map) || 0 == newCapacity)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	old_size = _map->m_size;
	m_NewData = _map->m_items;
    _map->m_items = (List**)malloc(newCapacity * sizeof(List*));
    if(NULL == _map->m_items)
    {
		_map->m_items = m_NewData;
  		return MAP_ALLOCATION_ERROR;
    }
	_map->m_size = newCapacity;		
    for(i = 0; i < old_size; ++i)
    {
		begin = ListItr_Begin(m_NewData[i]);
		end = ListItr_End(m_NewData[i]);
		while(begin != end)
		{
			cur = begin;
			begin = ListItr_Next(begin);
			dataHlder = (pair*)ListItr_Remove(cur);
			HashMap_Insert(_map,dataHlder->m_key,dataHlder->m_data);
			free(dataHlder);
		}
		List_Destroy(&m_NewData[i],NULL);
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
	pair  *checkData,*data ;
	ListItr begin, end;

	if(IS_INVALID(_map) || NULL ==  _pValue)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	
	if(NULL == _key)
	{
		return MAP_KEY_NULL_ERROR;
	}
	data = malloc(sizeof(pair));
	data->m_key = (void*)_key;
	idx = HashIdx((HashMap*)_map,data);

	begin = ListItr_Begin(_map->m_items[idx]);
	end = ListItr_End(_map->m_items[idx]);
	for(;begin != end ;begin = ListItr_Next(begin))
	{
		checkData = ListItr_Get(begin);
		if(_map->m_keysEqualFunc(checkData->m_key,(void*)_key))
		{
			data = (pair*)ListItr_Remove(begin);
			_pValue = data->m_data;
			return MAP_SUCCESS;
		}
	}
	
	return MAP_KEY_NOT_FOUND_ERROR;
}



/** 
 * This method is optional in the homewor 
 * @brief Iterate over all key-value pairs in the map.
 *                   Iteration will stop if _act returns a zero for a given pair
 * @details The user provided KeyValueActionFunction _action will be called for each element.  
 * @param[in] _map - Hash map to iterate over.
 * @param[in] _act - User provided function pointer to be invoked for each element
 * @returns number of times the user functions was invoked
 */
size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context)
{
	ListItr begin, end,cur;
	pair* dataHlder;
	size_t count = 0, size;
	int i;

	if(IS_INVALID(_map) || NULL == _action)
	{
		return MAP_UNINITIALIZED_ERROR;
	}
	size = _map->m_size;
	for(i = 0; i < size; ++i)
    {
		begin = ListItr_Begin(_map->m_items[i]);
		end = ListItr_End(_map->m_items[i]);
		while(begin != end)
		{
			++count;
			cur = begin;
			begin = ListItr_Next(begin);
			dataHlder = (pair*)ListItr_Remove(cur);
			if(!(_action(dataHlder->m_key,dataHlder->m_data,_context)))
			{
				return count;
			}
		}
	}
	return count;
}


#ifndef NDEBUG


Map_Stats HashMap_GetStatistics(const HashMap* _map)
{
	Map_Stats stats = {0};
	size_t size;
	int cur=0,count_max = 0, i;

	if(IS_INVALID(_map))
	{
		return stats;
	}
	size = _map->m_size;
	stats.numberOfBuckets = _map->m_size;
	for(i = 0;i < size;++i)
	{
		cur = List_Size(_map->m_items[i]);
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

static void Hash_Init(HashMap* _map,size_t _primeN, HashFunction _hashFunc, EqualityFunction _keysEqualFunc)
{
	_map->m_size = _primeN;
	_map->m_noItems = 0;
	_map->m_hashFunc = _hashFunc;
	_map->m_keysEqualFunc = _keysEqualFunc;
	_map->m_magic = MAGIC;	
}
#endif /* NDEBUG */



 /* 
    for(i = 0; i < newCapacity; ++i)
    {
    	_map->m_items[i] = List_Create();
  		if(NULL == _map->m_items[i])
  		{
  			for(j = 0;j < i;++j)
  			{
  				free(_map->m_items[j]);
  			}
			_map->m_items = m_NewData;
			return MAP_ALLOCATION_ERROR;
    	}
	}
	*/