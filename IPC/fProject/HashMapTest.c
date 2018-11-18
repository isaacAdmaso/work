#include <stdio.h>

#include "HashMap.h"
#include "mu_test.h"

# define NUM_OF_TEST 10000

size_t HashFunc1(const void* _key)
{
	return *(int*)_key * 17;
}


int EqualityFunc1(void* _firstKey,void* _secondKey)
{
	return (*(int*)_firstKey == *(int*)_secondKey);
}


int	KeyValueActionFunc1(const void* _key, void* _value, void* _context)
{
	return 0;
}

void KeyValInit(int* key, int* value, size_t size)
{
	int i;

	for(i = 0 ; i < size ; ++i)
	{
		key[i] = i;
		value[i] = i;
	}
}


/*************************************************************************/

UNIT(error_tests)
	
	HashMap* map;
	Map_Result status;
	int key, value, *ptrVal;

	map = HashMap_Create(0,1, HashFunc1, EqualityFunc1);
	ASSERT_THAT(map == NULL);
	
	map = HashMap_Create(4,1, NULL, EqualityFunc1);
	ASSERT_THAT(map == NULL);
	
	map = HashMap_Create(3,1, HashFunc1, NULL);
	ASSERT_THAT(map == NULL);
	

	map = HashMap_Create(7,1, HashFunc1, EqualityFunc1);



	status = HashMap_Rehash(NULL, 8);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);

	status = HashMap_Rehash(map, 0);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);

	status = HashMap_Insert(map, NULL, &value);
	ASSERT_THAT(status == MAP_KEY_NULL_ERROR);

	status = HashMap_Insert(NULL, &key, &value);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);

	status = HashMap_Remove(map, NULL, (void**)&ptrVal);
	ASSERT_THAT(status == MAP_KEY_NULL_ERROR);

	status = HashMap_Remove(NULL, &key, (void**)&ptrVal);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);

	status = HashMap_Remove(map, &key, (void**)&ptrVal);
	ASSERT_THAT(status == MAP_KEY_NOT_FOUND_ERROR);

	HashMap_Destroy(&map, NULL, NULL);


	status = HashMap_Remove(map, &key, (void**)&ptrVal);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);

	status = HashMap_Insert(map, &key, &value);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);

	status = HashMap_Rehash(map, 5);
	ASSERT_THAT(status == MAP_UNINITIALIZED_ERROR);

END_UNIT

UNIT(normal_tests)
	
	HashMap* map;
	Map_Result status;
	int key = 7, value = 8, *ptrVal;

	map = HashMap_Create(7,1, HashFunc1, EqualityFunc1);
	ASSERT_THAT(map != NULL);
	
	status = HashMap_Insert(map, &key, &value);
	ASSERT_THAT(status == MAP_SUCCESS);

	status = HashMap_Remove(map, &key, (void**)&ptrVal);
	ASSERT_THAT(status == MAP_SUCCESS);

	key = 9;

	status = HashMap_Remove(map, &key, (void**)&ptrVal);
	ASSERT_THAT(status == MAP_KEY_NOT_FOUND_ERROR);

	status = HashMap_Rehash(map, 8);
	ASSERT_THAT(status == MAP_SUCCESS);


	HashMap_Destroy(&map, NULL, NULL);

END_UNIT

UNIT(multiple_insert_rehash)
	
	HashMap* map;
	Map_Result status;
	int i, key[NUM_OF_TEST], value[NUM_OF_TEST];

	map = HashMap_Create(7,1, HashFunc1, EqualityFunc1);

	KeyValInit(key, value, NUM_OF_TEST);
	
	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Insert(map, &key[i], &value[i]);
		ASSERT_THAT(status == MAP_SUCCESS);
	}

	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Rehash(map, 8 + i);
		ASSERT_THAT(status == MAP_SUCCESS);
	}

	HashMap_Destroy(&map, NULL, NULL);

END_UNIT

UNIT(multiple_remove_check_value)
	
	HashMap* map;
	Map_Result status;
	int i, key[NUM_OF_TEST], value[NUM_OF_TEST], *ptrVal;

	map = HashMap_Create(7,1, HashFunc1, EqualityFunc1);

	KeyValInit(key, value, NUM_OF_TEST);
	
	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Insert(map, &key[i], &value[i]);
	}

	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Remove(map, &key[i], (void**)&ptrVal);
		ASSERT_THAT(status == MAP_SUCCESS);
		ASSERT_THAT(*ptrVal == i);
	}

	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Insert(map, &key[i], &value[i]);
	}
		
	status = HashMap_Rehash(map, 20);

	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Remove(map, &key[i], (void**)&ptrVal);
		ASSERT_THAT(status == MAP_SUCCESS);
		ASSERT_THAT(*ptrVal == i);
	}

	HashMap_Destroy(&map, NULL, NULL);

END_UNIT

UNIT(size_find_check)
	
	HashMap* map;
	Map_Result status;
	int i, key[NUM_OF_TEST], value[NUM_OF_TEST], *ptrVal = &i;

	map = HashMap_Create(7,1, HashFunc1, EqualityFunc1);

	KeyValInit(key, value, NUM_OF_TEST);
	
	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		HashMap_Insert(map, &key[i], &value[i]);
		ASSERT_THAT(HashMap_Size(map) == i + 1);
	}

	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Find(map, &key[i], (void**)&ptrVal);
		ASSERT_THAT(status == MAP_SUCCESS);
		ASSERT_THAT(*ptrVal == value[i]);
	}

	for(i = 0 ; i < 7 ; ++i)
	{
		HashMap_Remove(map, &key[i], (void**)&ptrVal);
		ASSERT_THAT(HashMap_Size(map) == NUM_OF_TEST - i - 1);
	
	}

	for(i = 0 ; i < 7 ; ++i)
	{
		HashMap_Insert(map, &key[i], &value[i]);
		
		ASSERT_THAT(HashMap_Size(map) == NUM_OF_TEST - 7 + i + 1);
	}

	HashMap_Rehash(map, 8 + i);
	
	ASSERT_THAT(HashMap_Size(map) == NUM_OF_TEST);

	for(i = 0 ; i < NUM_OF_TEST ; ++i)
	{
		status = HashMap_Find(map, &key[i], (void**)&ptrVal);
		ASSERT_THAT(status == MAP_SUCCESS);
		ASSERT_THAT(*ptrVal == value[i]);
	}


	HashMap_Destroy(&map, NULL, NULL);

END_UNIT


TEST_SUITE(framework test)

	TEST(error_tests)
	TEST(normal_tests)
	TEST(multiple_insert_rehash)
	TEST(multiple_remove_check_value)
	TEST(size_find_check)

END_SUITE

