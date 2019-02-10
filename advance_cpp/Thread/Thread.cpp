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
#include <iostream>


void* Thread::Work(void* _run)
{
	Runable* run = reinterpret_cast<Runable*>(_run);
    void *rtVal = nullptr;

    try
	{
		rtVal = run->Run();
	}
	catch (...)
	{
		throw;
	}
	
	return rtVal;
}

Thread::Thread(Runable& _run, bool _detach)
:m_run(_run)
{
    if(pthread_attr_init(&m_attr))
        throw PthreadAttrException();

    if(_detach)
    {
        pthread_attr_setdetachstate(&m_attr, PTHREAD_CREATE_DETACHED);
    }
    else
    {
        pthread_attr_setdetachstate(&m_attr, PTHREAD_CREATE_JOINABLE);
    }
    

    if(pthread_create(&m_id,&m_attr, &Work, (void*)&m_run))
        throw PthreadCreateException();

}

bool  Thread::CheckIfJoin()
{
    int status;
    if (pthread_attr_getdetachstate(&m_attr, &status))
        throw PthreadAttrException();
    return (status == PTHREAD_CREATE_JOINABLE);
}

Thread::~Thread()
{
    try
    {
        if(CheckIfJoin())
        {
            if(pthread_join( m_id, nullptr))
                throw PthreadJoinException();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


void** Thread::Join()
{
    void **retval = nullptr;
    if(CheckIfJoin())
    {
        if(pthread_join( m_id, retval))
            throw PthreadJoinException();
    }
    return retval;
}


void Thread::Detach()
{
    if(CheckIfJoin())
    {
        if (pthread_detach(m_id))
	    	throw PthreadDetachException();
    }
}
