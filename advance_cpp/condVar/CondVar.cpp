/**
 * @file CondVar.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-04
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <cerrno>
#include "CondVar.h"

CondVar::CondVar(Mutex& _mutex)
:m_mutex(_mutex)
{
    if(int rtVal = pthread_cond_init(&m_condVar,nullptr))
		throw CondVarInitException();
}

CondVar::~CondVar()
{
    if(pthread_cond_destroy(&m_condVar))
    {
        if(errno == EBUSY)
            throw CondVarDestroyException();
    }
}


void CondVar::NotifyOne()
{
	if (pthread_cond_signal(&m_condVar))
	{
		throw CondVarNotifyOneException();
	}
}

void CondVar::NotifyAll()
{
	if (pthread_cond_broadcast(&m_condVar))
	{
		throw CondVarNotifyAllException();
	}
}
