/**
 * @file Dispatcher.c pong
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-20
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "Dispatcher.h"
#include "MyMsq.h"
#include "CDR.h"/**for  Cdr_Size*/
#include "Manager.h"


#define MAGIC           80734624128
#define IS_INVALID(D)   ((NULL == (D)) || (D)->m_magic != MAGIC)




struct Dispatcher_t
{
    int             m_Msq;
    Manager_t*      m_SubM;/**TODO Manager_t** */
    size_t          m_magic;
};

/**
 * @brief create dispatcher 
 * 
 */
Dispatcher_t* Dispatcher_Create(char* _msqName,size_t _capacity,size_t _nThreads)
{
    Dispatcher_t* dispatch = NULL;
    msq_t msq;

    msq = Msq_CrInit(_msqName,0);
    if(msq == -1)
    {
        perror("\nMSQ INIT\n");
        return NULL;
    }
    if(!(dispatch = calloc(1,sizeof(Dispatcher_t))))
    {
        return NULL;
    }
    dispatch->m_Msq = msq;
    if(!(dispatch->m_SubM = Manager_Create(_capacity,_nThreads)))
    {
        free(dispatch);
        return NULL;
    }
    dispatch->m_magic = MAGIC;
   
    return dispatch;

}

/**
 * @brief  destroy dispatcher
 * 
 */
void Dispatcher_Destroy(Dispatcher_t* _dispatch)
{

    if(IS_INVALID(_dispatch))
    {
        return;
    }
    _dispatch->m_magic = 0;
    Manager_Destroy(_dispatch->m_SubM);
    Msq_Destroy(_dispatch->m_Msq);
    free(_dispatch);
    
}

/**
 * @brief dispatch
 * 
 */
void* Dispatcher_Run(void* _dispatch)
{
    void *handle;
    size_t sendSize;
    Dispatcher_t* dispatch = (Dispatcher_t*)_dispatch; 

    if(IS_INVALID(dispatch))
    {
        return NULL;
    }
    sendSize = Cdr_Size();

    handle = malloc(sendSize);
    while(Msq_Nmsgs(dispatch->m_Msq))
    {
        Msq_Receive(dispatch->m_Msq,MSG_TYPE_READ,handle,sendSize);
        Manager_Upsert(dispatch->m_SubM,handle);

    }
    free(handle);
    return (void*)((intptr_t)(1));
}

void *Dispatcher_ManagerPtr(Dispatcher_t* _disp)
{
    if(IS_INVALID(_disp))
    {
        return NULL;
    }
    return (void*)_disp->m_SubM;
}