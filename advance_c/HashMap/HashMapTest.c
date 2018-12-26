#include <stdio.h>
#include "HashMap.h"
#include "mu_test.h"

int keyArr[6] = {1,2,3,4,5,1};
int valArr[5] = {1,2,3,4,5};

size_t HashFunc(const void* _key)
{
	size_t res;
	const int* key = _key;
	
	res =  ((*key) * 2) -1;
	return res;
}


int EqualityFunc(void* _firstKey,void* _secondKey)
{
	const int *first = _firstKey, *second = _secondKey;
	return (*first == *second);
}

int	ActionFunc(const void* _key, void* _value, void* _context)
{
	const int *key = _key, *val = _value;
	
	printf("key: %d, value: %d\n", *key, *val);
	return 1;
}

UNIT(nulls)
	int* val;
	HashMap* map = NULL;
	
	map = HashMap_Create(0, HashFunc, EqualityFunc);
	ASSERT_THAT(NULL == map);
	
	map = HashMap_Create(5, NULL, EqualityFunc);
	ASSERT_THAT(NULL == map);
	
	map = HashMap_Create(5, HashFunc, NULL);
	ASSERT_THAT(NULL == map);
	
	map = HashMap_Create(5, HashFunc, EqualityFunc);
	ASSERT_THAT(NULL != map);	
	
	ASSERT_THAT(HashMap_Insert(NULL, keyArr + 0, valArr + 0) == MAP_UNINITIALIZED_ERROR);
	/*ASSERT_THAT(HashMap_Insert(map, keyArr + 0, NULL) == MAP_UNINITIALIZED_ERROR);*/
	ASSERT_THAT(HashMap_Insert(map, NULL, valArr + 0) == MAP_KEY_NULL_ERROR);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 0, valArr + 0) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 5, valArr + 1) == MAP_KEY_DUPLICATE_ERROR);
	
	HashMap_Destroy(&map, NULL, NULL);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 1, valArr + 1) == MAP_UNINITIALIZED_ERROR);
	
	ASSERT_THAT(HashMap_Remove(map, keyArr + 0, (void**)&val) == MAP_UNINITIALIZED_ERROR);
	
	map = HashMap_Create(5, HashFunc, EqualityFunc);
	ASSERT_THAT(NULL != map);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 0, valArr + 0) == MAP_SUCCESS);
	
	ASSERT_THAT(HashMap_Remove(NULL, keyArr + 5, (void**)&val) == MAP_UNINITIALIZED_ERROR);
	ASSERT_THAT(HashMap_Remove(map, keyArr + 0, NULL) == MAP_UNINITIALIZED_ERROR);
	ASSERT_THAT(HashMap_Remove(map, NULL, (void**)&val) == MAP_KEY_NULL_ERROR);
	ASSERT_THAT(HashMap_Remove(map, keyArr + 2, (void**)&val) == MAP_KEY_NOT_FOUND_ERROR);
	
	ASSERT_THAT(HashMap_Find(NULL, keyArr + 5, (void**)&val) == MAP_UNINITIALIZED_ERROR);
	ASSERT_THAT(HashMap_Find(map, keyArr + 5, NULL) == MAP_UNINITIALIZED_ERROR);
	ASSERT_THAT(HashMap_Find(map, NULL, (void**)&val) == MAP_KEY_NULL_ERROR);
	ASSERT_THAT(HashMap_Find(map, keyArr + 4, (void**)&val) == MAP_KEY_NOT_FOUND_ERROR);
	
	ASSERT_THAT(HashMap_Size(NULL) == 0);
	ASSERT_THAT(HashMap_ForEach(NULL, ActionFunc, NULL) == MAP_UNINITIALIZED_ERROR);
	ASSERT_THAT(HashMap_ForEach(map, NULL, NULL) == MAP_UNINITIALIZED_ERROR);
	
	HashMap_Destroy(&map, NULL, NULL);
	
	ASSERT_THAT(HashMap_Find(map, keyArr + 5, (void**)&val) == MAP_UNINITIALIZED_ERROR);
	ASSERT_THAT(HashMap_Size(map) == 0);
	ASSERT_THAT(HashMap_ForEach(map, ActionFunc, NULL) == MAP_UNINITIALIZED_ERROR);	
END_UNIT

UNIT(insert_remove_find_size_foreach)
	int* val;
	HashMap* map = NULL;
	
	map = HashMap_Create(5, HashFunc, EqualityFunc);
	ASSERT_THAT(NULL != map);
	
	ASSERT_THAT(HashMap_Insert(map, keyArr + 0, valArr + 0) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Size(map) == 1);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 1, valArr + 1) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Size(map) == 2);
	
	ASSERT_THAT(HashMap_ForEach(map, ActionFunc, NULL) == 2);
	
	ASSERT_THAT(HashMap_Remove(map, keyArr + 1, (void**)&val) == MAP_SUCCESS);
	ASSERT_THAT(*val == 2);
	ASSERT_THAT(HashMap_Size(map) == 1);
	
	ASSERT_THAT(HashMap_ForEach(map, ActionFunc, NULL) == 1);
	
	ASSERT_THAT(HashMap_Find(map, keyArr + 1, (void**)&val) == MAP_KEY_NOT_FOUND_ERROR);
	
	ASSERT_THAT(HashMap_Insert(map, keyArr + 1, valArr + 1) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Size(map) == 2);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 2, valArr + 2) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Size(map) == 3);
	
	ASSERT_THAT(HashMap_ForEach(map, ActionFunc, NULL) == 3);
	
	ASSERT_THAT(HashMap_Find(map, keyArr + 5, (void**)&val) == MAP_SUCCESS);
	ASSERT_THAT(*val == 1);	
	ASSERT_THAT(HashMap_Find(map, keyArr + 1, (void**)&val) == MAP_SUCCESS);
	ASSERT_THAT(*val == 2);
	
	ASSERT_THAT(HashMap_Remove(map, keyArr + 2, (void**)&val) == MAP_SUCCESS);
	ASSERT_THAT(*val == 3);
	ASSERT_THAT(HashMap_Size(map) == 2);
	
	ASSERT_THAT(HashMap_Remove(map, keyArr + 5, (void**)&val) == MAP_SUCCESS);
	ASSERT_THAT(*val == 1);
	ASSERT_THAT(HashMap_Size(map) == 1);
	
	ASSERT_THAT(HashMap_Remove(map, keyArr + 1, (void**)&val) == MAP_SUCCESS);
	ASSERT_THAT(*val == 2);
	ASSERT_THAT(HashMap_Size(map) == 0);
	
	ASSERT_THAT(HashMap_ForEach(map, ActionFunc, NULL) == 0);
	
	HashMap_Destroy(&map, NULL, NULL);			
END_UNIT

UNIT(rehash)
	HashMap* map = NULL;
	
	map = HashMap_Create(5, HashFunc, EqualityFunc);
	ASSERT_THAT(NULL != map);
	
	ASSERT_THAT(HashMap_Insert(map, keyArr + 0, valArr + 0) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 1, valArr + 1) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 2, valArr + 2) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 3, valArr + 3) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, keyArr + 4, valArr + 4) == MAP_SUCCESS);
	
	ASSERT_THAT(HashMap_ForEach(map, ActionFunc, NULL) == 5);	
	
	ASSERT_THAT(HashMap_Rehash(map, 6) == MAP_SUCCESS);
	
	ASSERT_THAT(HashMap_ForEach(map, ActionFunc, NULL) == 5);
	
	HashMap_Destroy(&map, NULL, NULL);
END_UNIT

TEST_SUITE(hash_tests)
	TEST(nulls)
	TEST(insert_remove_find_size_foreach)
	TEST(rehash)
END_SUITE


















