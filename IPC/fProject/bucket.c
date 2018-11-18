#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "bucket.h"
#include "HashMap.h"
#include "list_functions.h"

#define MAGIC 			192032874
#define IS_INVALID(B)  ((NULL == (B)) || ((B)->m_magic != MAGIC))

struct Bucket_t
{
	List* 				m_list;
	EqualityFunction 	m_keysEqualFunc;
	size_t 				m_magic;
}; 

typedef struct pair
{
	void* m_key;
	void* m_data;
}pair;

typedef struct DestroyPairFunc_t
{
	ElementDestroy m_keyDestroy; 
	ElementDestroy m_valDestroy;
}DestroyPairFunc_t;



/**
 * @brief create bucket using doubly linked list 
 * 
 */
Bucket_t* Bucket_Create(EqualityFunction _keysEqualFunc)
{
	Bucket_t*  bucket = NULL;

	if(!(bucket = malloc(sizeof(Bucket_t))))
	{
		return NULL;
	}
	if(!(bucket->m_list = List_Create()))
	{
		free(bucket);
		return NULL;
	}
	bucket ->m_keysEqualFunc = _keysEqualFunc;
	bucket->m_magic = MAGIC;

	return bucket;
}


static int Destroy_Pair(void* _element, void* _destryStruct)
{
	pair* nodeData = (pair*)_element;
	DestroyPairFunc_t* d_p_f = (DestroyPairFunc_t*)_destryStruct;

	if(!nodeData)
	{
		return 0;
	}
	d_p_f->m_keyDestroy(nodeData->m_key);
	d_p_f->m_valDestroy(nodeData->m_data);
	return 1;
}

static void Free_Pair(void* _pair)
{
	if(_pair)
		free(_pair);
}

/**
 * @brief destroy the bucket and the elements stored in it
 * 
 */
void Bucket_Destroy(Bucket_t* _bucket,ElementDestroy _keyDestroy,ElementDestroy _valDestroy)
{
	ListItr start,end;
	DestroyPairFunc_t d_p_f;


	if(IS_INVALID(_bucket))
	{
		return;
	}
	_bucket->m_magic = 0;

	if(_keyDestroy && _valDestroy)
	{
		d_p_f.m_keyDestroy = _keyDestroy;
		d_p_f.m_valDestroy = _valDestroy;
		start = ListItr_Begin(_bucket->m_list);
		end = ListItr_End(_bucket->m_list);
		ListItr_ForEach(start,end,Destroy_Pair,&d_p_f);
	}
		/*pair destroy*/
	List_Destroy(&(_bucket->m_list),Free_Pair);
}

/**
 * @brief insert key and value to index identifiable bucket 
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
Map_Result Bucket_Insert(Bucket_t**  _bucket, const void* _key, const void* _value, EqualityFunction1 _keysEqualFunc)
{
	pair *data,*checkData;
	ListItr begin, end;


	if(IS_INVALID(*_bucket))
	{
		if(!(*_bucket = Bucket_Create(_keysEqualFunc)))
		{
			return MAP_ALLOCATION_ERROR;
		}
	}

	if(!(data = (pair*)malloc(sizeof(pair))))
	{
		return MAP_ALLOCATION_ERROR;
	}
	data->m_key = (void*)_key;
	data->m_data =(void*)_value;

	begin = ListItr_Begin((*_bucket)->m_list);
	end = ListItr_End((*_bucket)->m_list);

	for(;begin != end ;begin = ListItr_Next(begin))
	{
		checkData = ListItr_Get(begin);
		if(_keysEqualFunc(checkData->m_key,data->m_key))
		{
			free(data);
			return MAP_KEY_DUPLICATE_ERROR;
		}
	}
	if((List_PushTail((*_bucket)->m_list,(void*)data)))
	{
		free(data);
		return MAP_ALLOCATION_ERROR;
	}
	return MAP_SUCCESS;
}

/**
 * @brief Remove a key-value pair from the hash map
 * and return value to _pValue
 * 
 */
Map_Result Bucket_Remove(Bucket_t* _bucket, const void* _searchKey, void** _pValue)
{
	pair *checkData;
	ListItr begin, end;

	if(IS_INVALID(_bucket))
	{
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	
	begin = ListItr_Begin(_bucket->m_list);
	end = ListItr_End(_bucket->m_list);
	/*itereq func || */
	for(;!ListItr_Equals((const ListItr)begin,(const ListItr) end) ;begin = ListItr_Next(begin))
	{
		checkData = ListItr_Get(begin);
		if(_bucket->m_keysEqualFunc(checkData->m_key,(void*)_searchKey))
		{
			checkData = (pair*)ListItr_Remove(begin);
			*_pValue = checkData->m_data;
			free(checkData);
			return MAP_SUCCESS;
		}
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}

void* Bucket_Get_First_Key(Bucket_t* _bucket)
{
	pair *checkData;
	ListItr itr;

	if(IS_INVALID(_bucket))
	{
		return NULL;
	}
	itr = ListItr_Begin(_bucket->m_list);
	checkData = (pair*)ListItr_Get(itr);
	return checkData->m_key;
}
/** 
 * @brief Get number of elements in the Bucket
 */
size_t Bucket_Size(Bucket_t* _bucket)
{
	if(IS_INVALID(_bucket))
	{
		return 0;
	}
	return List_Size((const List*)_bucket->m_list);
}

/**
 * @brief Find a value by key
 * 
 */
Map_Result Bucket_Find(const Bucket_t* _bucket, const void* _key, void** _pValue)
{
	pair  *checkData;
	ListItr begin, end;

	if(IS_INVALID(_bucket))
	{
		return MAP_KEY_NOT_FOUND_ERROR;
	}
	begin = ListItr_Begin(_bucket->m_list);
	end = ListItr_End(_bucket->m_list);
	for(;begin != end ;begin = ListItr_Next(begin))
	{
		checkData = ListItr_Get(begin);
		if(_bucket->m_keysEqualFunc(checkData->m_key,(void*)_key))
		{
			*_pValue = checkData->m_data;
			return MAP_SUCCESS;
		}
	}
	return MAP_KEY_NOT_FOUND_ERROR;
}

/**
 * @brief do  KeyValueActionFunction on each item
 * 
 */
size_t Bucket_ForEach(const Bucket_t* _bucket, KeyValueActionFunction _action, void* _context)
{
	ListItr begin, end,cur;
	pair* dataHolder;
	size_t count = 0;

	if(IS_INVALID(_bucket))
	{
		return count;
	}
	begin = ListItr_Begin(_bucket->m_list);
	end = ListItr_End(_bucket->m_list);
	while(begin != end)
	{
		++count;
		cur = begin;
		begin = ListItr_Next(begin);
		dataHolder = (pair*)ListItr_Get(cur);
		if(!(_action(dataHolder->m_key,dataHolder->m_data,_context)))
		{
			break;
		}
	}	
	return count;
}



