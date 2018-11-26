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
#include <unistd.h>
#include <stdlib.h>     /*calloc*/
#include "Dispatcher.h"
#include "query.h"
#include "Trigger.h"


#define EXECUTABLE              "./Reader"
#define INFILE                  "./file.txt"
#define OUTPUT                  "./log.txt"
#define QOUTPUT                 "./logQ.txt"
#define QOUTPUQ                 "./logq.txt"
#define MSGQUE_NAME_DEFAULT     "../../../"
#define CAPACITY                50
#define NTHREAD                 1




int main()
{
	pthread_t       *threadDispatchers;	
    Query_t         *query              = NULL;
    Trigger_t       *trigger            = NULL;
    Dispatcher_t    *dispatch           = NULL;
    char            executable[]        = EXECUTABLE;
    char            inFile[]            = INFILE;
    char            outFile[]           = OUTPUT;
    char            msqName[]           = MSGQUE_NAME_DEFAULT;
    int             i;

    trigger     = Trigger_Create(executable,inFile,outFile,msqName,NULL);
    dispatch    = Dispatcher_Create(msqName,CAPACITY,NTHREAD);
    query       = Query_Create(Dispatcher_ManagerPtr(dispatch));


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
    Query_Get_Subscriber(query,"1230",QOUTPUQ);
    Query_GetAll_Subscriber(query,QOUTPUT);
    Trigger_Destory(trigger);
    Query_Destroy(query);
    Dispatcher_Destroy(dispatch);
    return 0;
}



