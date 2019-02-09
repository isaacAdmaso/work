/**
 * @file CondVar.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __CONDVAR_H__
#define __CONDVAR_H__

#include <pthread.h>
#include "uncopy.h"
#include "Mutex.h"



class CondVar:private Uncopy
{
public:
    CondVar(Mutex& _mutex);
    ~CondVar();
   
    template <typename Predicate>
	void Wait(Predicate p);
	void NotifyOne();
	void NotifyAll();
private:
    pthread_cond_t m_condVar;
    Mutex&          m_mutex;
};

#include "CondVarException.hpp"
#include "CondVarPredicate.hpp"


#endif //__CONDVAR_H__