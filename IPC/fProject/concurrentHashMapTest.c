#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif

#include <stdio.h>
#include <pthread.h>

#include "HashMap.h"
#include "mu_test.h"


#define NTHREAD 50

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
    int i,*val;
	HashMap* map = NULL;
	pthread_t	tArr[NTHREAD];


	map = HashMap_Create(5,NTHREAD, HashFunc, EqualityFunc);
    /*
    for (i = 0;i < NTHREAD;++i)
    {
        pthread_create(&tArr[i], NULL, , );
    }
    */