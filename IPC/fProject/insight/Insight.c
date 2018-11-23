/**
 * @file Insight.c
 * @brief 
 * @version 0.1
 * @date 2018-11-22
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <pthread.h>
#include <stdio.h>      /*for debug(perror)*/
#include <stdlib.h>     /*calloc*/
#include "Trigger.h"
#include "Dispatcher.h"


#define EXECUTABLE              "./Reader"
#define INFILE                  "./file.txt"
#define OUTPUT                  "./log.txt"
#define MSGQUE_NAME_DEFAULT     "."
#define NTHREAD                 6




int main()
{
	pthread_t*		threadDispatchers;	        
    Trigger_t       *trigger            = NULL;
    Dispatcher_t    *dispatch           = NULL;
    char            executable[]        = EXECUTABLE;
    char            inFile[]            = INFILE;
    char            outFile[]           = OUTPUT;
    char            msqName[]           = MSGQUE_NAME_DEFAULT;
    int             i;

    trigger     = Trigger_Create(executable,inFile,outFile,msqName,NULL);
    dispatch    = Dispatcher_Create(msqName);


    Trigger_Run(trigger);

    threadDispatchers = (pthread_t*)calloc(NTHREAD, sizeof(pthread_t));
	if (!threadDispatchers)
	{
        perror("\nDispatchers array failed\n");
	}
    for(i = 0;i < NTHREAD;++i)
    {
        if(pthread_create(&threadDispatchers[i], NULL, Dispatcher_Run, dispatch));   
    }
    for (i = 0;i < NTHREAD;++i)
    {
       	pthread_join(threadDispatchers[i], NULL);
    }
    
    return 0;
}



