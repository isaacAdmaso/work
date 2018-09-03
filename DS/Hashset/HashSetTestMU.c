#include "HashSet.h"
#include "mu_test.h"
#include <stdio.h>
#include <stdlib.h>


/*
int CreatVector(Vector *v)
{
	int  i;
	int arr[]={1,2,3,4,5,36,77,81,29,120};
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		ASSERT_THAT(VectorAdd(v,arr[i]) == ERR_OK);
	}
	return PASS;
}
*/


static size_t mod(size_t _num)
{
	return _num % 3;
}


UNIT(hashBuild)
	HashSet *h;
	h = HashSetCreate(5,0.7,mod);
	ASSERT_THAT(h != NULL);
	HashSetDestroy(h);
END_UNIT

UNIT(hashBuild_capacityZero)
	HashSet *h;
	h = HashSetCreate(0,0.7,mod);
	ASSERT_THAT(NULL == h);
END_UNIT

UNIT(hashBuild_loadFactorbiggerThenOne)
	HashSet *h;
	h = HashSetCreate(53,1.5,mod);
	ASSERT_THAT(NULL == h);
END_UNIT

UNIT(HashSetInsert_normal)
	HashSet *h;
	h = HashSetCreate(3,0.5,mod);
	ASSERT_THAT(NULL != h);
	ASSERT_THAT(HashSetInsert(h,3) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetInsertALREADY_EXISTS)
	HashSet *h;
	h = HashSetCreate(3,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_ALREADY_EXISTS);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetInsertOVERFLOW)
	HashSet *h;
	h = HashSetCreate(2,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,7) == ERR_OVERFLOW);
	HashSetDestroy(h);
END_UNIT


UNIT(HashSetRemoveSuccessful)
	HashSet *h;
	h = HashSetCreate(2,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,6) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,55) == ERR_OK);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetRemoveNOT_FOUND)
	HashSet *h;
	h = HashSetCreate(2,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,6) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,33) == ERR_NOT_FOUND);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetdoesContains)
	HashSet *h;
	h = HashSetCreate(3,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,102) == ERR_OK);
	ASSERT_THAT(HashSetContains(h,6) != 0);
	ASSERT_THAT(HashSetContains(h,102) != 0);
	ASSERT_THAT(HashSetContains(h,55) != 0);
END_UNIT

UNIT(HashSetNOTContains)
	HashSet *h;
	h = HashSetCreate(3,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,102) == ERR_OK);
	ASSERT_THAT(HashSetContains(h,15) == 0);
	ASSERT_THAT(HashSetContains(h,12) == 0);
	ASSERT_THAT(HashSetContains(h,6) != 0);
END_UNIT

UNIT(HashSetSizeCheck)
	HashSet *h;
	h = HashSetCreate(3,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,102) == ERR_OK);
	ASSERT_THAT(HashSetSize(h) == 3);
	ASSERT_THAT(HashSetRemove(h,6) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,55) == ERR_OK);
	ASSERT_THAT(HashSetSize(h) == 1);
END_UNIT



UNIT(HashSetStatisticsNoInsert)
	HashSet *h;
	size_t maxCollisionsEver;
	float averageCollisions;
	h = HashSetCreate(3,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetStatistics(h,&maxCollisionsEver,&averageCollisions) == ERR_OK);
	ASSERT_THAT(maxCollisionsEver == 0);
	ASSERT_THAT(averageCollisions == 0);
END_UNIT


/*

UNIT(heapSize)
	Heap *h;
	Vector *v;
	h = NULL;
	ASSERT_THAT(HeapSize(h) == -1);
	v=VectorCreate(2,2);
	h = HeapBuild(v);
	ASSERT_THAT(HeapSize(h) == 0);
	CreatVector(v);
	h = HeapBuild(v);
	ASSERT_THAT(HeapSize(h) == 10);
	HeapDestroy(h);
	VectorDestroy(v);

END_UNIT

*/

TEST_SUITE(HashSet test)
	TEST(hashBuild)
	TEST(hashBuild_capacityZero)
	TEST(hashBuild_loadFactorbiggerThenOne)
	TEST(HashSetInsert_normal)
	TEST(HashSetInsertALREADY_EXISTS)
	TEST(HashSetInsertOVERFLOW)	
	TEST(HashSetRemoveNOT_FOUND)
	TEST(HashSetRemoveSuccessful)
	TEST(HashSetdoesContains)
	TEST(HashSetNOTContains)
	TEST(HashSetSizeCheck)
	TEST(HashSetStatisticsNoInsert)
END_SUITE

