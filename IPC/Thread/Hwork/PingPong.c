#define _DEFAULT_SOURCE /**<-? */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <assert.h>
#include <semaphore.h>

#include "Queue.h"
#define MAX 4
#define STR_OPT "vc:p:q:n:s:"

const char USAGE[]	            ="\nUsage: %s [-c] [-p] [-q] [-v] [-n number of messages] [-s msec]\n";
const char ERR_SEMA[]           = "\nERROR getting semaphore (F/E)!\n";
const char ECHO_CONSUMER_FIN[]	="\ngoodbye from thread #%d count of msg removed: %d \n";
const char ECHO_PRODUCER_FIN[]	="\ngoodbye from thread #%d,count of msg inserted: %d \n";
const char ECHO_INSERT[]	    ="\nthread #%ld Insert succesfully\n";
const char ECHO_REMOVE[]	    ="\nthread #%ld Remove succesfully\n";

typedef struct S_data
{
    Queue* m_myQ;
    sem_t *m_empty,*m_full;
    pthread_mutex_t *m_myMutex;
    int m_nOfItems;
    int m_sleepTime,m_count;

}S_data;


void* Producers_func(void* _sData)
{
    int i;
    S_data* data = _sData; 
    pthread_t id = pthread_self();

    for(i = 0;i < data->m_nOfItems;++i)
    {
        sem_wait(data->m_empty);
        pthread_mutex_lock(data->m_myMutex);
        QueueInsert(data->m_myQ,MAX);
        fprintf(stdout,ECHO_INSERT,id);
        pthread_mutex_unlock(data->m_myMutex);
        sem_post(data->m_full);
        data->m_count++;
        usleep(data->m_sleepTime);
    }
    return NULL;
}

void* Consumers_func(void* _sData)
{
    int max = 0;
    S_data* data = _sData; 
    pthread_t id = pthread_self();

    for(;;)
    {
        sem_wait(data->m_full);
        pthread_mutex_lock(data->m_myMutex);
        QueueRemove(data->m_myQ,&max);
        fprintf(stdout,ECHO_REMOVE,id);
        pthread_mutex_unlock(data->m_myMutex);
        sem_post(data->m_empty);
        usleep(data->m_sleepTime);
        data->m_count++;
    }
    return NULL;
}

void Data_Init(S_data* _thData,sem_t* _empty,sem_t* _full,Queue* _myQ
                ,int _nOfItems,int _sleepTime,pthread_mutex_t* _myMutex)
{
    _thData->m_empty = _empty;
    _thData->m_full = _full;
    _thData->m_myMutex = _myMutex;
    _thData->m_myQ = _myQ;
    _thData->m_nOfItems = rand()%_nOfItems + 1;
    _thData->m_sleepTime = rand()%_sleepTime; 
    _thData->m_count = 0;
}

int main(int argc, char *argv[])
{
    int opt = -1,verbose = 0,consumers = MAX/2,producers = MAX/2,nOfItems = MAX,sleepTime = MAX,i;
    size_t qSize = MAX/2,totSize = MAX;
    Queue* myQ = NULL;
    pthread_t* thArr;
    S_data *thDataArr;
    sem_t empty,full;
    pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
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
    if(sem_init(&empty, 0, qSize))
    {
        fprintf(stderr,ERR_SEMA);
        return 1;
    }
    if(sem_init(&full, 0, 0))
    {
        fprintf(stderr, ERR_SEMA);
        return 1;
    }

    totSize = consumers + producers;
    if(NULL == (thArr = malloc(totSize*sizeof(pthread_t))) ||
         NULL == (thDataArr = malloc(totSize*sizeof(S_data))))
    {
        fprintf(stderr, "\nError malloc\n");
        return 1;
    }
    srand (time(0));
    for(i = 0;i < producers;++i)
    {
        Data_Init(thDataArr + i,&empty,&full,myQ,nOfItems,sleepTime,&myMutex);
        if(pthread_create(&thArr[i], NULL, Producers_func,&thDataArr[i]))
        {
            fprintf(stderr, "\nError creating thread\n");
            return 1;
        }
    }
    for(;i < totSize;++i)
    {
        Data_Init(thDataArr + i,&empty,&full,myQ,nOfItems,sleepTime,&myMutex);
        if(pthread_create(&thArr[i], NULL, Consumers_func,&thDataArr[i]))
        {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }
    if (verbose)
		fprintf(stdout, "\njoin\n");
    for(i = 0; i < producers;++i)
    {
        if(pthread_join(thArr[i], NULL))
        {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
        fprintf(stdout,ECHO_PRODUCER_FIN,i,thDataArr[i].m_count);
    }
    for(; i < totSize;++i)
    {
        if(pthread_cancel(thArr[i]))
        {
            fprintf(stderr, "Error joining thread\n");
            return 1;
        }
        fprintf(stdout,ECHO_CONSUMER_FIN,i,thDataArr[i].m_count);
    }
    free(thArr);
    free(thDataArr);
    return 0;
}
