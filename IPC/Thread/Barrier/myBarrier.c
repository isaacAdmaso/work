#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); return 1; } while (0)

#define handle_error(msg) \
        do { perror(msg); return 1; } while (0)
#define MAGIC 987346013
#define IS_INVALID(B)  (((B) == NULL) || ((B)->m_magic != MAGIC) )


typedef  void (*_doSomeThing)(void*);

typedef struct Barrier
{
    pthread_mutex_t m_myMutex;
    pthread_cond_t  m_cond_var;
    size_t          m_capacity; 
    size_t          m_magic;  
    size_t          m_inThreadCounter;
    size_t          m_outThreadCounter;
    size_t          m_nBatch;
    int             m_isExit;  
}Barrier_t;

Barrier_t* Barrier_Init(size_t _numberOfThread)
{
    Barrier_t* barrier;
    int error;
    
    barrier = calloc(_numberOfThread,sizeof Barrier_t);
    if(!barrier)
    {
        perror("barrier calloc ");
        return NULL;
    }

    if(error = pthread_mutex_init(&(barrier->m_myMutex),NULL))
	{
		perror("pthread_mutex_init");
		free(barrier);
		return NULL;	
	}
	if(error = pthread_cond_init(&(barrier->m_cond_var),NULL))
	{
		perror(error, "pthread_cond_init");
		free(barrier);
		return NULL;
	}
    barrier->m_capacity = _numberOfThread;
    barrier->m_threadCounter = 0;
    barrier->m_nBatch = 0;
    barrier->m_isExit = 1;
    barrier->m_magic = MAGIC;
    return barrier;
}

int Barrier_Wait(Barrier_t* _barrier,_doSomeThing _toDo,void* _context)
{
    int error,group = 0;

    if(error = pthread_mutex_lock(&(_barrier->m_myMutex)))
    {
        handle_error_en(error, "pthread_mutex_barrier LOCK");
    }
    ++_barrier->m_inThreadCounter;
    
    while ((((_barrier->m_inThreadCounter / _barrier->m_capacity) =! _barrier->m_nBatch) ||
        !(_barrier->m_inThreadCounter % _barrier->m_capacity)) && _barrier->m_isExit)
    {
        pthread_cond_wait(&(_barrier->m_cond_var),&(_barrier->m_myMutex)); 
    }
    if (!(_barrier->m_inThreadCounter % _barrier->m_capacity)) 
    {
        pthread_cond_broadcast(&(_barrier->m_cond_var));
        _barrier->m_isExit = 0;
    }
    if(error = pthread_mutex_unlock(&(_barrier->m_myMutex)))
    {
        handle_error_en(error, "pthread_mutex_barrier UNLOCK");
    }
    if(_toDo)
    {
        _toDo(_context);
    }
    if(error = pthread_mutex_lock(&(_barrier->m_myMutex)))
    {
        handle_error_en(error, "pthread_mutex_barrier LOCK");
    }
    ++(_barrier->m_outThreadCounter);
    while (!(_barrier->m_outThreadCounter % _barrier->m_capacity))
    {
        pthread_cond_wait(&(_barrier->m_cond_var),&(_barrier->m_myMutex)); 
    }
    if (!(_barrier->m_outThreadCounter % _barrier->m_capacity)) 
    {
        _barrier->m_isExit = 1;
        ++(_barrier->m_nBatch);
        pthread_cond_broadcast(&(_barrier->m_cond_var));
    }
    if(error = pthread_mutex_unlock(&(_barrier->m_myMutex)))
    {
        handle_error_en(error, "pthread_mutex_barrier UNLOCK");
    }
    return 0;
}


void Barrier_Destroy(Barrier_t* _barrier)
{
    if(IS_INVALID(_barrier))
        return;
    pthread_mutex_destroy(&(_barrier->m_myMutex));
    pthread_cond_destroy(&(_barrier->m_cond_var));
    free(_barrier);
}