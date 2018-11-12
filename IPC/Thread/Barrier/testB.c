#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "myBarrier.h"

#define SIZE_COUNT 1
#define EXPECTED_VAL(N) ((N) * ((N) - 1))/2

int countArray[SIZE_COUNT] = {0};

typedef struct Arg
{
	int m_sum;
	int m_numItr;
	int m_indx;
	Barrier_t* m_barr;
}Arg;

void TempSumFunc(void* _sum)
{
	int i;
	int* sum = (int*)_sum;

	for(i = 0; i < SIZE_COUNT; ++i)
	{
		*sum += countArray[i]; 
	}
	
	printf("zoti--%d--\n", *sum);
	*(int*)_sum = *sum; 
}

void* sumFunc(void* _arg)
{
	int j;
	Arg* arg = (Arg*)_arg;
	
	for(j = 0; j < arg->m_numItr; ++arg->m_numItr)
	{
		Barrier_Wait(arg->m_barr, TempSumFunc, (void*)&arg->m_sum);
		
	}
	return NULL;
}

void* countFunc(void* _arg)
{
	int i, j;
	Arg* arg = (Arg*)_arg;
	
	for(j = 0; j < arg->m_numItr; ++j)
	{
		for(i = 0; i < (arg->m_indx); ++i)
		{
			++(countArray[arg->m_indx]);
		}
		Barrier_Wait(arg->m_barr, NULL, NULL);
	}
	return NULL;
}

int main()
{
	pthread_t summarizer;
	pthread_t* counters; 
	int i, sum = 0, res;
	Arg arg;
	
	arg.m_barr = Barrier_Create(SIZE_COUNT + 1);
	arg.m_sum = 0;
	arg.m_numItr = 5;
	
	counters = (pthread_t*)calloc(SIZE_COUNT,sizeof(pthread_t));
	if(!counters)
	{
		printf("Error: Array Allocation\n");
		return 0;	
	}
	
	if(pthread_create(&summarizer, NULL, sumFunc, (void*)&arg))
	{
		perror("Error:");
		return 0;
	}
	
	for(i = 0; i < SIZE_COUNT; ++i)
	{
		arg.m_indx = i;
		if(pthread_create(&counters[i], NULL, countFunc, (void*)&arg) != 0)
		{
			perror("Error:");
			return 0;
		}
	}
		
	for(i = 0; i < SIZE_COUNT; ++i)
	{
		if(pthread_join(counters[i], NULL) != 0)
		{
			perror("Error:");
			return 0;
		}
	}
	pthread_join(summarizer, NULL);

	res = EXPECTED_VAL(SIZE_COUNT);
	if(res == sum)
	{
		printf("SUCCESS !!!!!\n");
	}
	
	printf("The total sum is: %d\n", sum);
	Barrier_Destroy(arg.m_barr);
	free(counters);

	
	return 0;
}




























