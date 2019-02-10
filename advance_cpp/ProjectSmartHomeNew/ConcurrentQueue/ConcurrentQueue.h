/**
 * @file ConcurrentQueue.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __CONCURRENTQUEUE_H__
#define __CONCURRENTQUEUE_H__

#include <queue>
#include "Mutex.h"
#include "CondVar.h"


template <class T>
class ConcurrentQueue
{
public:
	bool    Pop(T& _rtVal);
	bool    Push(const T& _elem);
    bool  Is_Empty();
private:
	std::queue<T>	m_queue;
	Mutex			m_mutex;
	CondVar			m_condVar;
};


#include "ConcurrentQueue.hpp"



#endif // __CONCURRENTQUEUE_H__