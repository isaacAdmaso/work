/**
 * @file Lock.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <cerrno>
#include "Mutex.h"


Mutex::Mutex()
{
    if(pthread_mutex_init(&m_mutex,nullptr))
		throw MutexInitException();
}

Mutex::~Mutex()
{
    if(pthread_mutex_destroy(&m_mutex))
     {
        if(errno == EBUSY)
            throw MutexDestroyException();
    }
}
void Mutex::lock()
{
    if(pthread_mutex_lock(&m_mutex))
		throw MutexLockException();
}

void Mutex::unlock()
{
    if(pthread_mutex_unlock(&m_mutex))
		throw MutexUnlockException();		
}

pthread_mutex_t* Mutex::Get()
{
    return &m_mutex;
}
