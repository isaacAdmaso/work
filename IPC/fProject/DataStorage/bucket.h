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

typedef enum Bucket_Result {
	Bucket_SUCCESS = 0,
	Bucket_UNINITIALIZED_ERROR, 		/**< Uninitialized Bucket error 	*/
	Bucket_KEY_NULL_ERROR, 			/**< Key was null 				*/
	Bucket_KEY_DUPLICATE_ERROR, 		/**< Duplicate key error 		*/
	Bucket_KEY_NOT_FOUND_ERROR, 		/**< Key not found 				*/
	Bucket_ALLOCATION_ERROR, 			/**< Allocation error 	 		*/
	Bucket_OVERFLOW_ERROR				/**< NEED TO USE RE_HASH FUNC*/
} Bucket_Result;

typedef struct Bucket_t Bucket_t;   /** declaration of bucket type */
typedef void (*ElementDestroy)(void* _item);
typedef int (*EqualityFunction1)(void *_firstKey, void *_secondKey);
typedef void* (*UpdateFunction1)(void *_firstItem, void *_secondItem);
typedef int	(*KeyValueActionFunction1)(const void* _key, void* _value, void* _context);


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
 /*TODO BUCKET STATUS  */
Bucket_Result Bucket_Insert(Bucket_t**  _bucket, const void* _key, const void* _value, EqualityFunction1 _keysEqualFunc);

/**
 * insert if not exist else update
*/
int Bucket_Upsert(Bucket_t**  _bucket, const void* _key,void* _value, EqualityFunction1 _keysEqualFunc,UpdateFunction1 _action);

/**
 * @brief Remove a key-value pair from the hash map
 * and return value to _pValue
 * 
 */

/*TODO upsert*/
 
Bucket_Result Bucket_Remove(Bucket_t* _bucket, const void* _searchKey, void** _pValue);

/**
 * @brief for rehash
 * 
 */
 /*TODO pop(keyRt,valueRt) */
void* Bucket_Get_First_Key(Bucket_t* _bucket);

/** 
 * @brief Get number of elements in the Bucket
 */
size_t Bucket_Size(Bucket_t* _bucket);

/**
 * @brief Find a value by key
 * 
 */
Bucket_Result Bucket_Find(const Bucket_t* _bucket, const void* _key, void** _pValue);

/**
 * @brief do  KeyValueActionFunction on each item
 * 
 */
size_t Bucket_ForEach(const Bucket_t* _bucket, KeyValueActionFunction1 _action, void* _context);





#endif /*__BUCKET_H__ */
