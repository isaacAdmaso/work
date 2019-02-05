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
#include <errno.h>
#include "Mutex.h"


Mutex::Mutex()
{
    int rtVal = 0;
    
    if(rtVal = pthread_mutex_init(&m_mutex,nullptr))
        throw rtVal; 
}

Mutex::~Mutex()
{
    int rtVal = 0;
    
    if(rtVal = pthread_mutex_destroy(&m_mutex))
     {
        if(errno == EBUSY)
            throw errno;
    }
}
void Mutex::lock()
{
    int rtVal = 0;
    
    if(rtVal = pthread_mutex_lock(&m_mutex))
        throw rtVal; 
}

void Mutex::unlock()
{
    int rtVal = 0;
    
    if(rtVal = pthread_mutex_unlock(&m_mutex))
        throw rtVal; 
}
