#include <stdio.h>

#include "mu_test.h"
#include "HashMap.h"

#define SIZE 15

/**********************************************************************************************
											Function
**********************************************************************************************/
int keyArr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
int arr2[] = {3,6,9,12,15,18,21,24,27,30,33,36,39,42,45};


Map_Result FillHash (HashMap* _map)
{
	int i;
	
	for (i=0; i<SIZE; ++i)
	{
		if( HashMap_Insert(_map, (void*)&keyArr[i], (void*)&arr2[i]) != MAP_SUCCESS)
		{
			return MAP_OVERFLOW_ERROR;
		}
	}
	
	return MAP_SUCCESS;
}


Map_Result RemoveHash (HashMap* _map)
{
	int i;
	
	for (i=0; i<SIZE-5; ++i)
	{
		if( HashMap_Remove(_map, (void*)&keyArr[i], (void*)&arr2[i]) != MAP_SUCCESS)
		{
			return MAP_OVERFLOW_ERROR;
		}
	}
	
	return MAP_SUCCESS;
}



size_t Hashfunc (const void* _key)
{
	const int num = *(int*)_key;
	
	return (num + 10);
}


int EqualityFunc (void* _firstKey,void* _secondKey)
{
	const int num1 = *(int*)_firstKey;
	const int num2 = *(int*)_secondKey;
	
	return (num1 == num2);
}



int ActionFunction (const void* _key, void* _value, void* _context)
{
	const int key = *(int*)_key;
	const int value = *(int*)_value;
	
	printf ("Key = %d, Value = %d\n",key, value);
	
	return 0;
}



UNIT (hash_insert)
	int key1=1, key2=2, key3=3, value1=3, value2=6, value3=9, context = 100;
	HashMap* map;
	ASSERT_THAT ((map = HashMap_Create(4,Hashfunc,EqualityFunc)) != NULL);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key1, (void*)&value1) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key2, (void*)&value2) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key3, (void*)&value3) == MAP_SUCCESS);
	HashMap_ForEach(map, ActionFunction, (void*)&context);
	HashMap_Destroy(&map,NULL,NULL);
END_UNIT




UNIT (hash_remove)
	int key1=1, key2=2, key3=3, value1=3, value2=6, value3=9, context = 100;
	int* value = &value3;
	HashMap* map;
	ASSERT_THAT ((map = HashMap_Create(4,Hashfunc,EqualityFunc)) != NULL);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key1, (void*)&value1) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key2, (void*)&value2) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key3, (void*)&value3) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Remove(map, (void*)&key1, (void**)&value) == MAP_SUCCESS);
	ASSERT_THAT(*value == value1);
	HashMap_ForEach(map, ActionFunction, (void*)&context);
	HashMap_Destroy(&map,NULL,NULL);

END_UNIT




UNIT (hash_find)
	int key1=1, key2=2, key3=3, value1=3, value2=6, value3=9, context = 100;
	int* value;
	HashMap* map;
	ASSERT_THAT ((map = HashMap_Create(4,Hashfunc,EqualityFunc)) != NULL);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key1, (void*)&value1) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key2, (void*)&value2) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(map, (void*)&key3, (void*)&value3) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Remove(map, (void*)&key3, (void**)&value) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Remove(map, (void*)&key1, (void**)&value1) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Find(map, (void*)&key2, (void**)&value) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Find(map, (void*)&key3, (void**)&value) == MAP_KEY_NOT_FOUND_ERROR);
	ASSERT_THAT(HashMap_Size(map) == 1);
	HashMap_ForEach(map, ActionFunction, (void*)&context);
	HashMap_Destroy(&map,NULL,NULL);
END_UNIT



UNIT (hash_ReHash)
	int context = 100;
	HashMap* map;
	ASSERT_THAT ((map = HashMap_Create(4,Hashfunc,EqualityFunc)) != NULL);
	ASSERT_THAT(FillHash(map) == MAP_SUCCESS);
	HashMap_ForEach(map, ActionFunction, (void*)&context);
	printf("\nReHash Function\n");
	ASSERT_THAT(HashMap_Rehash(map, 2) == MAP_SUCCESS);
	HashMap_ForEach(map, ActionFunction, (void*)&context);
	ASSERT_THAT(RemoveHash(map) == MAP_OVERFLOW_ERROR);
	printf("\nAfter Remove\n");
	HashMap_ForEach(map, ActionFunction, (void*)&context);
	HashMap_Destroy(&map,NULL,NULL);
END_UNIT




TEST_SUITE(Hash)
	TEST(hash_insert)
	
	TEST(hash_remove)
	
	TEST(hash_find)
	
	TEST(hash_ReHash)
END_SUITE	














