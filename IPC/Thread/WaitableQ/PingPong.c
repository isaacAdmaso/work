#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 500
#endif
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <assert.h>

#include "Queue.h"
#define MAX 4
#define STR_OPT "vc:p:q:n:s:"

const char USAGE[]	            ="\nUsage: %s [-c] [-p] [-q] [-v] [-n number of messages] [-s msec]\n";
const char ECHO_CONSUMER_FIN[]	="\ngoodbye from thread #%d count of msg removed: %d \n";
const char ECHO_PRODUCER_FIN[]	="\ngoodbye from thread #%d,count of msg inserted: %d \n";
const char ECHO_INSERT[]	    ="\nthread #%ld Insert succesfully\n";
const char ECHO_REMOVE[]	    ="\nthread #%ld Remove msg No%d from thread #%d succesfully\n";

union Msg
{
    short m_idTh;
    short m_nMsg;
    int m_toSend;
};

typedef struct S_data
{
    Queue* m_myQ;
    int m_nOfItems;
    int m_sleepTime;
    int m_count;
    union Msg m_msg;

}S_data;


void* Producers_func(void* _sData)
{
    short i;
    S_data* data = _sData; 
    pthread_t id = pthread_self();

    for(i = 0;i < data->m_nOfItems;++i)
    {
        data->m_msg.m_nMsg = i;
        QueueInsert(data->m_myQ,data->m_msg.m_toSend);
        fprintf(stdout,ECHO_INSERT,id);
        data->m_count++;
        usleep(data->m_sleepTime);
        QueuePrint(data->m_myQ);
    }
    return NULL;
}

void* Consumers_func(void* _sData)
{
    union Msg max;
    S_data* data = _sData; 
    pthread_t id = pthread_self();

    for(;;)
    {
        QueuePrint(data->m_myQ);
        QueueRemove(data->m_myQ,&(max.m_toSend));
        fprintf(stdout,ECHO_REMOVE,id,max.m_nMsg,max.m_idTh);
        usleep(data->m_sleepTime);
        data->m_count++;
    }
    return NULL;
}

void Data_Init(S_data* _thData,Queue* _myQ,int _nOfItems,int _sleepTime,short _id)
{
    _thData->m_myQ = _myQ;
    _thData->m_nOfItems = rand()%_nOfItems + 1;
    _thData->m_sleepTime = rand()%_sleepTime; 
    _thData->m_count = 0;
    _thData->m_msg.m_idTh = _id;
}

int main(int argc, char *argv[])
{
    int opt = -1,verbose = 0,consumers = MAX/2,producers = MAX/2,nOfItems = MAX,sleepTime = MAX;
    short i;
    size_t qSize = MAX/2,totAmount = MAX;
    Queue* myQ = NULL;
    pthread_t* thArr;
    S_data *thDataArr;
    extern char *optarg;
	extern int optind;

    while (-1 != (opt = getopt(argc, argv,STR_OPT)))
    {
		switch (opt)
        {
		case 'v':	
			verbose = 1;
			break;
		case 'c':	
			consumers = atoi(optarg);
			break;
		case 'p':	
			producers = atoi(optarg);
			break;
		case 'q':	
			qSize = atoi(optarg);
			break;
		case 'n':	
			nOfItems = atoi(optarg);
			break;
		case 's':	
			sleepTime = atoi(optarg) * 1000;
			break;
		default: /* '?' */
			fprintf(stderr, USAGE, argv[0]);
			return 1;
		}
	}

    if (verbose)
		fprintf(stdout, "\ninit\n");
    myQ = QueueCreate(qSize);
    assert(myQ != NULL);
    
    totAmount = consumers + producers;
    if(NULL == (thArr = malloc(totAmount*sizeof(pthread_t))) ||
         NULL == (thDataArr = malloc(totAmount*sizeof(S_data))))
    {
        fprintf(stderr, "\nError malloc\n");
        return 1;
    }
    srand (time(0));
    for(i = 0;i < producers;++i)
    {
        Data_Init(thDataArr + i,myQ,nOfItems,sleepTime,i);
        if(pthread_create(&thArr[i], NULL, Producers_func,&thDataArr[i]))
        {
            fprintf(stderr, "\nError creating thread\n");
            return 1;
        }
    }
    for(;i < totAmount;++i)
    {
        Data_Init(thDataArr + i,myQ,nOfItems,sleepTime,i);
        if(pthread_create(&thArr[i], NULL, Consumers_func,&thDataArr[i]))
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }
    if (verbose)
		fprintf(stdout, "\njoin\n");
    QueuePrint(myQ);
    for(i = 0; i < producers;++i)
    {
        if(pthread_join(thArr[i], NULL))
        {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
        fprintf(stdout,ECHO_PRODUCER_FIN,i,thDataArr[i].m_count);
    }
    QueuePrint(myQ);

    for(; i < totAmount;++i)
    {
        if(pthread_cancel(thArr[i]))
        {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
        fprintf(stdout,ECHO_CONSUMER_FIN,i,thDataArr[i].m_count);
    }
    QueuePrint(myQ);
    free(thArr);
    free(thDataArr);
    QueueDestroy(myQ);
    return 0;
}
