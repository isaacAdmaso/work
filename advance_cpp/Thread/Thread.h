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
    Thread(Runable& _run, bool _detach = true);
    ~Thread();
    void** Join();
    void Detach();

private:
	static void* Work(void* _this);
    bool  CheckIfJoin();

private:
    pthread_t m_id;
    pthread_attr_t m_attr;
    Runable& m_run;
};


#include "ThreadException.hpp"

#endif //__THREAD_H__