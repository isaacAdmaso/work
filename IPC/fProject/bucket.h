/**
 * @file bucket.h
 * @brief self manage "bucket" for hash map
 * @version 0.1
 * @date 2018-11-15
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BUCKET_H__
#define __BUCKET_H__


#include <stddef.h>
#include "list_functions.h" /**bucket functions */
#include "HashMap.h"


typedef struct Bucket_t Bucket_t;   /** declaration of bucket type */
typedef void (*ElementDestroy)(void* _item);
typedef int (*EqualityFunction1)(void *_firstKey, void *_secondKey);

/**
 * @brief return pointer of new bucket 
 * 
 */
Bucket_t* Bucket_Create();

/**
 * @brief destroy the bucket and the elements stored in it
 * 
 */
void Bucket_Destroy(Bucket_t* _bucket,ElementDestroy _keyDestroy,ElementDestroy _valDestroy);

/**
 * @brief insert key and value to a bucket 
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
Map_Result Bucket_Insert(void* _key ,void* _value ,Bucket_t**  _bucket ,EqualityFunction1 _keysEqualFunc);

/**
 * @brief Remove a key-value pair from the hash map
 * and return value to _pValue
 * 
 */
Map_Result Bucket_Remove(Bucket_t* _bucket, const void* _searchKey, void** _pValue);

/**
 * @brief for rehash
 * 
 */
void* Bucket_Get_First_Key(Bucket_t* _bucket);

/** 
 * @brief Get number of elements in the Bucket
 */
size_t Bucket_Size(Bucket_t* _bucket);

/**
 * @brief Find a value by key
 * 
 */
Map_Result Bucket_Find(const Bucket_t* _bucket, const void* _key, void** _pValue);

/**
 * @brief do  KeyValueActionFunction on each item
 * 
 */
size_t Bucket_ForEach(const Bucket_t* _bucket, KeyValueActionFunction _action, void* _context);





#endif /*__BUCKET_H__ */