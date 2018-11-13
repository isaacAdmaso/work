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

#include "myBarrier.h"
#define handle_error_en(en, msg) \
        do { errno = en; perror(msg); return 1; } while (0)

#define handle_error(msg) \
        do { perror(msg); return 1; } while (0)
#define MAGIC 987346013
#define IS_INVALID(B)  (((B) == NULL) || ((B)->m_magic != MAGIC) )



struct Barrier
{
    pthread_mutex_t m_myMutex;
    pthread_cond_t  m_cond_var;
    size_t          m_capacity; 
    size_t          m_magic;  
    size_t          m_inThreadCounter;
    size_t          m_outThreadCounter;
    size_t          m_nBatch;
    int             m_isExit;  
};

Barrier_t* Barrier_Create(size_t _numberOfThread)
{
    Barrier_t* barrier;
    int error;
    
    barrier = calloc(1,sizeof (Barrier_t));
    if(!barrier)
    {
        perror("barrier calloc ");
        return NULL;
    }

    if((error = pthread_mutex_init(&(barrier->m_myMutex),NULL)))
	{
		perror("pthread_mutex_init");
		free(barrier);
		return NULL;	
	}
	if((error = pthread_cond_init(&(barrier->m_cond_var),NULL)))
	{
		perror("pthread_cond_init");
		free(barrier);
		return NULL;
	}
    barrier->m_capacity = _numberOfThread;
    barrier->m_inThreadCounter = 0;
    barrier->m_outThreadCounter = 0;
    barrier->m_nBatch = 0;
    barrier->m_isExit = 1;
    barrier->m_magic = MAGIC;
    return barrier;
}
static int Barrier_In(Barrier_t* _barrier)
{
    int error,id,batch;

    if((error = pthread_mutex_lock(&(_barrier->m_myMutex))))
    {
        handle_error_en(error, "pthread_mutex_barrier LOCK");
    }
    id = (++(_barrier->m_inThreadCounter)) % _barrier->m_capacity;
    batch = _barrier->m_inThreadCounter / _barrier->m_capacity;
    while (((batch != _barrier->m_nBatch) ||  id) && _barrier->m_isExit)
    {
        pthread_cond_wait(&(_barrier->m_cond_var),&(_barrier->m_myMutex)); 
    }
    if (!id) 
    {
        pthread_cond_broadcast(&(_barrier->m_cond_var));
        _barrier->m_isExit = 0;
    }
    if((error = pthread_mutex_unlock(&(_barrier->m_myMutex))))
    {
        handle_error_en(error, "pthread_mutex_barrier UNLOCK");
    }
    return 0;
}

static int Barrier_Out(Barrier_t* _barrier)
{
    int error,id;

    if((error = pthread_mutex_lock(&(_barrier->m_myMutex))))
    {
        handle_error_en(error, "pthread_mutex_barrier LOCK");
    }
    id = (++_barrier->m_outThreadCounter)  % _barrier->m_capacity;
    while (id)
    {
        pthread_cond_wait(&(_barrier->m_cond_var),&(_barrier->m_myMutex)); 
    }
    ++(_barrier->m_nBatch);
    _barrier->m_isExit = 1;
    pthread_cond_broadcast(&(_barrier->m_cond_var));
    if((error = pthread_mutex_unlock(&(_barrier->m_myMutex))))
    {
        handle_error_en(error, "pthread_mutex_barrier UNLOCK");
    }
    return 0;

}


int Barrier_Wait(Barrier_t* _barrier,_doSomeThing _toDo,void* _context)
{
    int error;

    error = Barrier_In(_barrier);
   
    if(_toDo)
    {
        _toDo(_context);
    }

    error = Barrier_Out(_barrier);

    return error+error;
}


void Barrier_Destroy(Barrier_t* _barrier)
{
    if(IS_INVALID(_barrier))
        return;
    pthread_mutex_destroy(&(_barrier->m_myMutex));
    pthread_cond_destroy(&(_barrier->m_cond_var));
    free(_barrier);
}