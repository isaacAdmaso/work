/**
 * @file ConcurrentQueue.hpp
 * @author your name (you@domain.com)
 * @brief implementation for my queue
 * @version 0.1
 * @date 2019-02-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __CONCURRENTQUEUE_HPP__
#define __CONCURRENTQUEUE_HPP__

template <typename T>
struct QPredicate
{
	Predicate(const std::queue<T>& _queue):m_queue(_queue){}	
	bool operator()() const
	{
		return m_queue.empty();
	}
	const std::queue<T>& m_queue;
};


template <typename T>
bool ConcurrentQueue<T>::Pop(T& _rtVal)
{
	m_mutex.lock();
	
	try
	{
		m_condVar.Wait(QPredicate <std::queue<T> >(m_queue));
		_rtVal = m_queue.front();
		m_queue.pop();
		m_mutex.unlock(); 	
		return true;
	}
	catch(const std::exception& e)
	{
		m_mutex.unlock(); 
		throw;
	}
}

template <typename T>
bool ConcurrentQueue<T>::Push(const T& _elem)
{
    m_mutex.lock();
    
    try
	{
		m_queue.push(_elem);
		m_condVar.NotifyOne();
		m_mutex.unlock();
	}
	catch(const std::exception& e)
	{
		m_mutex.unlock(); 
		throw;
	}
	
}
template <typename T>
bool  ConcurrentQueue<T>::Is_Empty()
{
    m_mutex.lock();
    try
    {
        bool rtVal = m_queue.empty();
		m_mutex.unlock(); 
        return rtVal;
    }
    catch(const std::exception& e)
    {
        m_mutex.unlock(); 
		throw;
    }
}

#endif // __CONCURRENTQUEUE_HPP__