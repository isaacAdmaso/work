/**
 * @file Lock.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __MLOCK_H__
#define __MLOCK_H__
#include <unistd.h>
#include <pthread.h>


class Mutex
{
public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();

private:
    pthread_mutex_t m_mutex;
};


#endif //__MLOCK_H__