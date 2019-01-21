/**
 * @brief 
 * 
 */
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <stdint.h>
#include "Lock.h"


template<class T>
class SingleTone
{
public:
	~SingleTone(){delete single_ptr;}
	static SingleTone& GetInstance(void* _null = nullptr);
	T m_single;

private:
	SingleTone(){}
	SingleTone(SingleTone&);
	SingleTone& operator=(const SingleTone&);
private:
	static SingleTone* single_ptr;
	static Mutex m_mutex;
};

template<class T>
SingleTone<T>& SingleTone<T>::GetInstance(void* _null )
{	
	if(_null)
		std::cout<<(intptr_t)_null<<" dident locked"<<std::endl;
	if(!single_ptr)
	{
		if(_null)
			std::cout<<(intptr_t)_null<<" locked"<<std::endl;

		m_mutex.lock();
		if(!single_ptr)
		{
			volatile SingleTone* temp = new SingleTone();
			single_ptr = (SingleTone*)temp;
			std::cout<<"real created"<<std::endl;
		}
		m_mutex.unlock();
	}
	return *single_ptr;
}

template<class T>
Mutex SingleTone<T>::m_mutex;

template<class T>
SingleTone<T>* SingleTone<T>::single_ptr = nullptr;



#endif //__SINGLETON_H__
