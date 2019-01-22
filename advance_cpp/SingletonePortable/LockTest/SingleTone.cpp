/**
 * @file SingleTone.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <pthread.h>
#include <iostream>
#include <stdint.h>

#include "SingleTone.h"
#define NUM 100

using namespace std;



int main(int argc, char const *argv[])
{
    intptr_t arr[NUM] = {0};
	pthread_t counters[NUM]; 

    for(int i = 0; i < NUM; ++i)
	{
		arr[i] = i;
		if(pthread_create(&counters[i], NULL,(void*(*)(void *))SingleTone<int>::GetInstance,(void*)(arr[i])) != 0)
		{
			return 1;
		}
	}
		
    for(int i = 0; i < NUM; ++i)
	{
		pthread_join(counters[i],nullptr);
	}	
    return 0;
}
