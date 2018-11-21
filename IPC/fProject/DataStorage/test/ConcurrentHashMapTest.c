#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#include "HashMap.h"
#include "mu_test.h"


#define NTHREAD 10

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


void* ThreadInsert(void*_contex)
{
	HashMap* map = (HashMap*)_contex; 
	/* init i */
	static int i;
	
	/*
	HashMap_ForEach(map, ActionFunc, NULL);
	*/
	i++;
	if (HashMap_Insert(map, keyArr + i,valArr + i) == MAP_SUCCESS)
	{
		printf("\ninsert success: key %d value %d\n",keyArr[i],valArr[i]);
	}
	else
	{
		printf("\ninsert not succeed: key %d value %d\n",keyArr[i],valArr[i]);
	}
	printf("\n out insert\n");
	return NULL;
}
void* ThreadRemove(void*_contex)
{
	int num = 3,*val = &num ;
	static int i;
	HashMap* map = (HashMap*)_contex; 
	i++;

/*
	HashMap_ForEach(map, ActionFunc, NULL);
*/
	if(HashMap_Remove(map, keyArr + i, (void**)&val) == MAP_SUCCESS)
	{
		
		printf("\nremove success: key %d value %d\n",keyArr[i],*val);

		printf("\nremove success\n");
	}
	else
	{
		printf("\nremove not succeed: key %d value %d\n",keyArr[i],*val);
	}
	printf("\n out remove\n");
	return NULL; 
}
UNIT(Multithread)
	HashMap* map = NULL;
	pthread_t	tArr[NTHREAD];
    int i;

	map = HashMap_Create(2,NTHREAD, HashFunc, EqualityFunc);
	
    for (i = 0;i < NTHREAD/2;++i)
    {
        pthread_create(&tArr[i], NULL,ThreadInsert ,(void*)map );
    }
	/*
	HashMap_ForEach(map, ActionFunc, NULL);
    */
	for (i = 0; i < NTHREAD/2; ++i)
    {

       	pthread_join(tArr[i], NULL);
    }
	for (i = NTHREAD/2;i < NTHREAD;++i)
    {
        pthread_create(&tArr[i], NULL,ThreadRemove ,(void*)map);
    }
	for (i = NTHREAD/2; i < NTHREAD; ++i)
    {

       	pthread_join(tArr[i], NULL);
    }
END_UNIT

TEST_SUITE(hash_tests)
	TEST(Multithread)
END_SUITE
