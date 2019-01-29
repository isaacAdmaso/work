/**
 * @file Thread.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-28
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __THREAD_H__
#define __THREAD_H__
#include <pthread.h>
#include "Runable.h"


class Thread
{
public:
    Thread(Runable& _run);
    ~Thread();
    void** Join();
    void Detach();
    static void* Work(void* _p);

private:
    bool  CheckIfJoin();

private:
    pthread_t m_id;
    pthread_attr_t m_attr;
    Runable& m_run;
};



#endif //__THREAD_H__