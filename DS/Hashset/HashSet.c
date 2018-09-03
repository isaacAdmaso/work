#include "HashSet.h"
#include<stdlib.h>
#include<stdio.h>

#define MAGIC 1073741824
#define MININPUT 1
#define IS_INVALID(H) ((NULL == (H)) || (H)->m_magic != MAGIC)
#define REHASH(I,K) (((I)+5)%(K))
#define FREE 0
#define NOT_OCCUPIED -1


typedef size_t(*HashFunc)(size_t);
struct HashSet 
{
	size_t m_magic;
	int *m_items;
	size_t m_size;
	size_t m_noItems;
	size_t m_capacity;
	HashFunc m_hashF;
	size_t m_maxReHashOps;
	size_t m_insertCount;
	size_t m_totalReHash;
};


static int IsPrime(int _n)
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

static int GetNumber(int _number)
{
	while (1)
    {
        if (IsPrime(_number)) break;
        ++_number;
    }
    return _number;
}


HashSet* HashSetCreate(size_t _capacity, float _loadFactor, HashFunc _func)
{
	HashSet *h;
	int primeN;/*real capacity*/
	/*parameter check*/
	if(_capacity <= MININPUT || _loadFactor >= MININPUT)
	{
		return NULL;
	}
	h = (HashSet*)malloc(sizeof(HashSet));
	if(NULL == h)
	{
		return NULL;
	}
	primeN = GetNumber((int)(_capacity/_loadFactor));
	h->m_items = (int*)calloc(primeN,sizeof(int));
	if(NULL == h->m_items)
	{
		free(h);
		return NULL;
	}
	h->m_size = primeN;
	h->m_noItems = 0;
	h->m_hashF = _func;
	h->m_capacity = _capacity;
	h->m_maxReHashOps = 0;
	h->m_insertCount = 0;
	h->m_totalReHash = 0;
	h->m_magic = MAGIC;
	return h;
}
	
void HashSetDestroy(HashSet* _set)
{
	/*parameter check*/
	if(!IS_INVALID(_set))
	{
		_set->m_magic = 0;
		free(_set->m_items);		
		free(_set);
	}
}


		
ADTErr HashSetInsert(HashSet* _set, size_t _data)
{
	size_t hashIndex,reHashC = 0;
	/*parameter check*/
	if(IS_INVALID(_set))	
	{
		return ERR_NOT_INITIALIZED;
	}
	if(_set->m_capacity == _set->m_noItems)
	{
		return ERR_OVERFLOW;
	}
	/*hashing data*/
	hashIndex = _set->m_hashF(_data);
	while(_set->m_items[hashIndex] > FREE)
	{
		if(_set->m_items[hashIndex] == _data)
			return ERR_ALREADY_EXISTS;
		++reHashC;
		hashIndex = REHASH(hashIndex,_set->m_size);
	}				
	_set->m_items[hashIndex] = _data;
	++(_set->m_noItems);
	_set->m_totalReHash+=reHashC;
	_set->m_maxReHashOps = (_set->m_maxReHashOps < reHashC) ? reHashC : _set->m_maxReHashOps;
	++_set->m_insertCount;
	return ERR_OK;
}
		
ADTErr HashSetRemove(HashSet* _set, size_t _data)
{
	size_t hashIndex;
	/*parameter check*/
	if(IS_INVALID(_set))	
	{
		return ERR_NOT_INITIALIZED;
	}
	/*hashing data*/
	
	hashIndex = _set->m_hashF(_data);
	if(_set->m_items[hashIndex] == _data)
	{
		_set->m_items[hashIndex] = NOT_OCCUPIED;
		--(_set->m_noItems);
		return ERR_OK;
	}
	/*rehashing data*/
	do
	{	
		hashIndex = REHASH(hashIndex,_set->m_size);
		if(_set->m_items[hashIndex] == _data)
		{
			_set->m_items[hashIndex] = NOT_OCCUPIED;
			--(_set->m_noItems);
			return ERR_OK;
		}
	}while(_set->m_items[hashIndex] > FREE);
	return ERR_NOT_FOUND;
}

int HashSetContains(const HashSet* _set, size_t _data)
{
	size_t hashIndex;
	if(IS_INVALID(_set))	
	{
		return ERR_NOT_INITIALIZED;
	}
	hashIndex = _set->m_hashF(_data);
	while(_set->m_items[hashIndex] > FREE)
	{
		if(_set->m_items[hashIndex] == _data)
		{
			return (int)_data;
		}
		hashIndex = REHASH(hashIndex,_set->m_size);
	}
	return 0;
}
	
size_t HashSetSize(const HashSet* _set)
{
	if(IS_INVALID(_set))	
	{
		return 0;
	}
	return	_set->m_noItems;	
}		
		
ADTErr HashSetStatistics(const HashSet* _set, size_t *_maxCollisionsEver, float *_averageCollisions)
{
	if(IS_INVALID(_set) || NULL == _maxCollisionsEver || NULL ==_averageCollisions)	
	{
		return ERR_NOT_INITIALIZED;
	}
	*_maxCollisionsEver = _set->m_maxReHashOps;
	*_averageCollisions = (_set->m_insertCount != 0) ? _set->m_totalReHash/_set->m_insertCount : 0;
	return ERR_OK;
}


		
		
		
		
		
		
		
		
		
		


