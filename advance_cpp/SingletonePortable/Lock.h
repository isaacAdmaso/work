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
#ifndef __LOCK_H__
#define __LOCK_H__
#ifdef _WIN32
    #include <Windows.h>
#elif __linux__
    #include <unistd.h>
    #include <pthread.h>
#endif


class Mutex
{
public:
    Mutex();
    ~Mutex();
    void lock();
    void unlock();

private:
    #ifdef _WIN32
        HANDLE ghMutex;
    #elif __linux__
        pthread_mutex_t m_mutex;
    #endif 
};
#endif //__LOCK_H__