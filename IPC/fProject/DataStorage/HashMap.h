#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <stddef.h>  /* size_t */

/** 
 *  @file HashMap.h
 *  @brief Generic Hash map of key-value pairs implemented with separate chaining using linked lists.
 *	
 *  @details  The hash map (sometimes called dictionary or associative array)
 *  is a set of distinct keys (or indexes) mapped (or associated) to values.
 *  size of allocated table will be the nearest prime number greater than requestedcapacity
 *  Lists used for chaining will be allocated lazely.
 *
 *  @author Muhammad Zahalqa  (MuhammadZ@experis.co.il)
 * 
 *  @bug No known bugs.
 */


typedef struct HashMap HashMap;

typedef enum Map_Result {
	MAP_SUCCESS = 0,
	MAP_UNINITIALIZED_ERROR, 		/**< Uninitialized map error 	*/
	MAP_KEY_NULL_ERROR, 			/**< Key was null 				*/
	MAP_KEY_DUPLICATE_ERROR, 		/**< Duplicate key error 		*/
	MAP_KEY_NOT_FOUND_ERROR, 		/**< Key not found 				*/
	MAP_ALLOCATION_ERROR, 			/**< Allocation error 	 		*/
	MAP_OVERFLOW_ERROR				/**< NEED TO USE RE_HASH FUNC*/
} Map_Result;


typedef size_t (*HashFunction)(const void* _key);
typedef int (*EqualityFunction)(void* _firstKey, void* _secondKey);
typedef int	(*KeyValueActionFunction)(const void* _key, void* _value, void* _context);
typedef void (*Destroy)(void* _item);
typedef void* (*UpdateFunction)(void *_firstItem, void *_secondItem);/**for upsert */



/** 
 * @brief Create a new hash map with given capcity and key characteristics.
 * @param[in] _capacity - Expected max capacity 
 * 						  shall be rounded to nearest larger prime number.
 * @param[in] _hashFunc - hashing function for keys
 * @param[in] _keysEqualFunc - equality check function for keys. 
 * @param[in] _nTread - Expected max number of threads. 
 * @return newly created map or null on failure
 */
HashMap* HashMap_Create(size_t _capacity, size_t _nTread, HashFunction _hashFunc, EqualityFunction _keysEqualFunc);


/**
 * @brief destroy hash map and set *_map to null
 * @param[in] _map : map to be destroyed
 * @param[optional] _keyDestroy : pointer to function to destroy keys
 * @param[optional] _valDestroy : pointer to function to destroy values 
 * @details optionally destroy all keys and values using user provided functions
 */
void HashMap_Destroy(HashMap** _map, void (*_keyDestroy)(void* _key), void (*_valDestroy)(void* _value));


/** 
 * @brief Adjust map capacity and rehash all key/value pairs
 * @param[in] _map - exisiting map
 * @param[in] _newCapacity - new capacity shall be rounded to nearest larger prime number.
 * @return MAP_SUCCESS or MAP_ALLOCATION_ERROR
 */
Map_Result HashMap_Rehash(HashMap *_map, size_t newCapacity);


/** 
 * @brief Insert a key-value pair into the hash map.
 * @param[in] _map - Hash map adt to insert to, must be initialized
 * @param[in] _key - key to serve as index 
 * @param[in] _value - The value to associate with the key 
 * @return Success indicator
 * @retval  MAP_SUCCESS	on success
 * @retval  MAP_KEY_DUPLICATE_ERROR	if key alread present in the map
 * @retval  MAP_KEY_NULL_ERROR
 * @retval  MAP_ALLOCATION_ERROR on failer to allocate key-value pair
 * @retval  MAP_UNINITIALIZED_ERROR
 * 
 * @warning key must be unique and destinct
 */
Map_Result HashMap_Insert(HashMap* _map, void* _key, void* _value);

/**
 * @brief insert if not exist else update
 * 
 */
Map_Result HashMap_Upsert(HashMap* _map, void* _key, void* _value,UpdateFunction _update);

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
Map_Result HashMap_Remove(HashMap* _map, const void* _searchKey, void** _pValue);


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
Map_Result HashMap_Find(const HashMap* _map, const void* _key, void** _pValue);


/**
 * @brief Get number of key-value pairs inserted into the hash map
 */
size_t HashMap_Size(const HashMap* _map);


/** 
 * This method is optional in the homewor 
 * @brief Iterate over all key-value pairs in the map.
 *                   Iteration will stop if _act returns a zero for a given pair
 * @details The user provided KeyValueActionFunction _action will be called for each element.  
 * @param[in] _map - Hash map to iterate over.
 * @param[in] _act - User provided function pointer to be invoked for each element
 * @returns number of times the user functions was invoked
 */
size_t HashMap_ForEach(const HashMap* _map, KeyValueActionFunction _action, void* _context);


#ifndef NDEBUG

typedef struct Map_Stats {
	size_t numberOfBuckets;    /* empty + not empty buckets */
	size_t numberOfChains;     /* none empty chains (having non zero length) */
	size_t maxChainLength;     /* length of longest chain */
	size_t averageChainLength; /* average length of none empty chains */
} Map_Stats;

Map_Stats HashMap_GetStatistics(const HashMap* _map);

#endif /* NDEBUG */


#endif /* __HASHMAP_H__ */





