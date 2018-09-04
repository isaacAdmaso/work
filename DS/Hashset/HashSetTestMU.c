#include "HashSet.h"
#include "mu_test.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 11
#define CAPA 5

static size_t mod(size_t _num)
{
	return _num % SIZE;
}


UNIT(hashBuild)
	HashSet *h;
	h = HashSetCreate(CAPA,0.7,mod);
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
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(NULL != h);
	ASSERT_THAT(HashSetInsert(h,3) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetInsertALREADY_EXISTS)
	HashSet *h;
	int i;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	for(i=0;i<CAPA-2;++i)
	{
		ASSERT_THAT(HashSetInsert(h,i*7) == ERR_OK);
	}	
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_ALREADY_EXISTS);
	ASSERT_THAT(HashSetInsert(h,14) == ERR_ALREADY_EXISTS);
	ASSERT_THAT(HashSetRemove(h,6) == ERR_OK);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetInsertOVERFLOW)
	HashSet *h;
	int i;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	for(i=0;i<CAPA;++i)
	{
		ASSERT_THAT(HashSetInsert(h,i*3) == ERR_OK);
	}	
	ASSERT_THAT(HashSetInsert(h,7) == ERR_OVERFLOW);
	HashSetDestroy(h);
END_UNIT


UNIT(HashSetRemoveSuccessful)
	HashSet *h;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,6) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,55) == ERR_OK);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetRemoveNOT_FOUND)
	HashSet *h;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,6) == ERR_OK);
	ASSERT_THAT(HashSetRemove(h,33) == ERR_NOT_FOUND);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetdoesContains)
	HashSet *h;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,102) == ERR_OK);
	ASSERT_THAT(HashSetContains(h,6) != 0);
	ASSERT_THAT(HashSetContains(h,102) != 0);
	ASSERT_THAT(HashSetContains(h,55) != 0);
	HashSetDestroy(h);	
END_UNIT

UNIT(HashSetNOTContains)
	HashSet *h;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	ASSERT_THAT(HashSetInsert(h,6) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,55) == ERR_OK);
	ASSERT_THAT(HashSetInsert(h,102) == ERR_OK);
	ASSERT_THAT(HashSetContains(h,15) == 0);
	ASSERT_THAT(HashSetContains(h,12) == 0);
	ASSERT_THAT(HashSetContains(h,6) != 0);
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetSizeCheck)
	HashSet *h;
	int i;
	int arr[]={34,54,65,23,87,11,90,78,45,33,59};
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	for(i=0;i<CAPA;++i)
	{
		ASSERT_THAT(HashSetInsert(h,arr[i]) == ERR_OK);
		ASSERT_THAT(HashSetSize(h) == (i+1));
		
	}
	for(i=0;i<CAPA;++i)
	{
		ASSERT_THAT(HashSetRemove(h,arr[i]) == ERR_OK);
		ASSERT_THAT(HashSetSize(h) == (CAPA-1-i));
	}
	HashSetDestroy(h);
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
	HashSetDestroy(h);
END_UNIT

UNIT(HashSetStatisticscheck)
	HashSet *h;
	int i;
	size_t maxCollisionsEver;
	float averageCollisions;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	for(i=0;i<CAPA;++i)
	{
		ASSERT_THAT(HashSetInsert(h,i) == ERR_OK);
		
	}
	ASSERT_THAT(HashSetSize(h) == CAPA);
	ASSERT_THAT(HashSetInsert(h,134) == ERR_OVERFLOW);
	ASSERT_THAT(HashSetStatistics(h,&maxCollisionsEver,&averageCollisions) == ERR_OK);
	/*HashSetForEach(h);*/
	HashSetDestroy(h);
END_UNIT	

UNIT(HashSetStatisticscheck2)
	HashSet *h;
	int i;
	size_t maxCollisionsEver;
	float averageCollisions;
	h = HashSetCreate(CAPA,0.5,mod);
	ASSERT_THAT(h != NULL);
	for(i=0;i<CAPA;++i)
	{
		ASSERT_THAT(HashSetInsert(h,i*SIZE) == ERR_OK);
		
	}
	ASSERT_THAT(HashSetSize(h) == CAPA);
	ASSERT_THAT(HashSetInsert(h,4) == ERR_OVERFLOW);
	ASSERT_THAT(HashSetStatistics(h,&maxCollisionsEver,&averageCollisions) == ERR_OK);
	ASSERT_THAT(maxCollisionsEver != 0);
	ASSERT_THAT(averageCollisions != 0);
	printf("%lu, %f",maxCollisionsEver,averageCollisions);
	HashSetDestroy(h);
END_UNIT	
/*
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
	TEST(HashSetStatisticscheck)
	TEST(HashSetStatisticscheck2)
END_SUITE

