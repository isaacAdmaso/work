/**
 * @file Thread.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Thread.h"
#include <errno.h>


void* Thread::Work(void* _p)
{
    Thread* thread = (Thread*)_p;
    return (void*)thread->m_run.Run(); 
}

Thread::Thread(Runable& _run)
:m_run(_run)
{
    int rtVal = pthread_attr_init(&m_attr);
    if(rtVal)
        throw rtVal;

    rtVal = pthread_create(&m_id,&m_attr,Work, (void*)this);
    if(rtVal)
        throw rtVal;

}

bool  Thread::CheckIfJoin()
{
    int status;
    int rtVal = pthread_attr_getdetachstate(&m_attr, &status);
    if (rtVal)
        throw rtVal;
    return (status == PTHREAD_CREATE_JOINABLE);
}

Thread::~Thread()
{
    if(CheckIfJoin())
    {
        int rtVal = pthread_join( m_id, nullptr);
        if(rtVal)
            throw rtVal;
    }
}


void** Thread::Join()
{
    void **retval = nullptr;
    if(CheckIfJoin())
    {
        int rtVal = pthread_join( m_id, retval);
        if(rtVal)
            throw rtVal;
    }
    return retval;
}


void Thread::Detach()
{
    if(CheckIfJoin())
    {
        int rtVal = pthread_attr_setdetachstate(&m_attr, PTHREAD_CREATE_DETACHED);
        if (rtVal)
            throw rtVal;
    }
}
