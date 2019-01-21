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
#include <iostream>
#include <errno.h>
#include "Lock.h"


#ifdef __linux__
Mutex::Mutex()
{
    if(pthread_mutex_init(&m_mutex,nullptr))
    {
        std::cerr<<"mutex init fail";
    }
}
Mutex::~Mutex()
{
    pthread_mutex_destroy(&m_mutex);
}

void Mutex::lock()
{
    if(pthread_mutex_lock(&m_mutex))
    {
        std::cerr<<"mutex lock fail";

    }
}
void Mutex::unlock()
{
    if(pthread_mutex_unlock(&m_mutex))
    {
        std::cerr<<"mutex unlock fail";
    }
}
#elif _WIN32
Mutex::Mutex()
{
}
Mutex::~Mutex()
{
}
void Mutex::lock()
{
}
void Mutex::unlock()
{
}

#endif //__linux__