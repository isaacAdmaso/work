#include "HashMap.h"
#include "person.h"
#include "mu_test.h"
#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

#define SIZE 100


static size_t mod(const void* _null)
{
	return *(int*)_null % SIZE ;
}


UNIT(hashBuild)
	HashMap *h;

	h = HashMap_Create(6,mod,Person_Eq2);
	ASSERT_THAT(h != NULL);
	HashMap_Destroy(&h,NULL,NULL);
END_UNIT
UNIT(hashBuild_capacityZero)
	HashMap *h;
	h = HashMap_Create(0,mod,Person_Eq2);
	ASSERT_THAT(NULL == h);
END_UNIT

UNIT(hashBuild_Null_param)
	HashMap *h;
	h = HashMap_Create(53,NULL,Person_Eq2);
	ASSERT_THAT(NULL == h);
	h = HashMap_Create(53,mod,NULL);
	ASSERT_THAT(NULL == h);
END_UNIT

UNIT(HashSetInsert_normal)
	HashMap *h;
	h = HashMap_Create(SIZE,mod,Person_Eq2);
	ASSERT_THAT(NULL != h);
	ASSERT_THAT(HashMap_Insert(h,&(people[0].id),&people[0]) == MAP_SUCCESS);
	ASSERT_THAT(HashMap_Insert(h,&(people[1].id),&people[1]) == MAP_SUCCESS);
	HashMap_Destroy(&h,NULL,NULL);
END_UNIT

UNIT(HashSetInsertALREADY_EXISTS)
	HashMap *h;
	int i;
	h = HashMap_Create(SIZE,mod,Person_Eq2);
	ASSERT_THAT(h != NULL);
	for(i=0;i<SIZE;++i)
	{
		ASSERT_THAT(HashMap_Insert(h,&(people[i].id),people+i) == MAP_SUCCESS);
	}	
	for(i=0;i<2;++i)
	{
		ASSERT_THAT(HashMap_Insert(h,&(people[i].id),people+i) == MAP_KEY_DUPLICATE_ERROR);
	}	
	HashMap_Destroy(&h,NULL,NULL);
END_UNIT

/*
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
		ASSERT_THAT(HashSetInsert(h,i+1) == ERR_OK);
		
	}
	ASSERT_THAT(HashSetSize(h) == CAPA);
	ASSERT_THAT(HashSetInsert(h,134) == ERR_OVERFLOW);
	ASSERT_THAT(HashSetStatistics(h,&maxCollisionsEver,&averageCollisions) == ERR_OK);
	HashSetForEach(h);
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
	ASSERT_THAT(HashSetRemove(h,SIZE) == ERR_OK);
	ASSERT_THAT(HashSetContains(h,2*SIZE) != 0);
	HashSetDestroy(h);
END_UNIT	
*/

TEST_SUITE(HashSet test)
	TEST(hashBuild)
	TEST(hashBuild_capacityZero)
	TEST(hashBuild_Null_param)
	TEST(HashSetInsert_normal)
	TEST(HashSetInsertALREADY_EXISTS)
/*
	TEST(HashSetInsertOVERFLOW)	
	TEST(HashSetRemoveNOT_FOUND)
	TEST(HashSetRemoveSuccessful)
	TEST(HashSetdoesContains)
	TEST(HashSetNOTContains)
	TEST(HashSetSizeCheck)
	TEST(HashSetStatisticsNoInsert)
	TEST(HashSetStatisticscheck)
	TEST(HashSetStatisticscheck2)
*/
END_SUITE

