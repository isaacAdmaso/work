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
#include "MyMsq.h"
#include "query.h"
#include "Trigger.h"


#define EXECUTABLE              "./Reader"
#define INFILE                  "./file.txt"
#define OUTPUT                  "./log.txt"
#define QOUTPUT                 "./logQ.txt"
#define QOUTPUQ                 "./logq.txt"
#define MSGQUE_NAME_DEFAULT     "../../../"
#define CAPACITY                3
#define NTHREAD                 1




int main()
{
	pthread_t       triggerThread ;	
	pthread_t       *threadDispatchers;	
    Query_t         *query              = NULL;
    Trigger_t       *trigger            = NULL;
    Dispatcher_t    *dispatch           = NULL;
    char            executable[]        = EXECUTABLE;
    char            inFile[]            = INFILE;
    char            outFile[]           = OUTPUT;
    int            msqID;
    int             i;



    if(-1 == (msqID = Msq_CrInit(MSGQUE_NAME_DEFAULT,1)))
        return 1;
    if(!(trigger = Trigger_Create(executable,inFile,outFile,msqID,NULL)))
        return 1;
    if(!(dispatch = Dispatcher_Create(msqID,CAPACITY,NTHREAD)))
        return 1;
    if(!(query = Query_Create(Dispatcher_ManagerPtr(dispatch))))
        return 1;


    if(pthread_create(&triggerThread, NULL, Trigger_Run, trigger))
    {
        return 1;
    };

	if (!(threadDispatchers = (pthread_t*)calloc(NTHREAD, sizeof(pthread_t))))
	{
        perror("\nDispatchers array failed\n");
	}
    for(i = 0;i < NTHREAD;++i)
    {
        if(pthread_create(&threadDispatchers[i], NULL, Dispatcher_Run, dispatch))
        {
            return 1;
        }  
    }
    for (i = 0;i < NTHREAD;++i)
    {
       	pthread_join(threadDispatchers[i], NULL);
    }
    printf("\n%d\n",Query_Get_Subscriber(query,"1",QOUTPUQ));
    printf("\n%d\n",Query_GetAll_Subscriber(query,QOUTPUT));
    free(threadDispatchers);
    Trigger_Destory(trigger);
    Query_Destroy(query);
    Dispatcher_Destroy(dispatch);
    return 0;
}



