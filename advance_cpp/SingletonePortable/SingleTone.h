/**
 * @brief 
 * 
 */
#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include "Lock.h"

template<class T>
class SingleTone
{
public:
	~SingleTone(){delete single_ptr;}
	static SingleTone* GetInstance();

private:
	SingleTone(){}
private:
	static SingleTone* single_ptr;
	static Mutex m_mutex;
	T m_single;
};

template<class T>
SingleTone<T>* SingleTone<T>::GetInstance()
{
	if(!single_ptr)
	{
		m_mutex.lock();
		if(!single_ptr)
		{
			volatile SingleTone* temp = new SingleTone();
			single_ptr = temp;
		}
		m_mutex.unlock();
	}
	return single_ptr;
}
template<class T>
Mutex SingleTone<T>::m_mutex;

template<class T>
SingleTone<T>* SingleTone<T>::single_ptr = nullptr;



#endif //__SINGLETON_H__
/*class DBServer
{
private:
	static DBServer* theServer;
public:
	static DBServer* getInstance()
	{
		if (!theServer) {
			theServer = new DBServer;
		}
		return theServer;
	}
private:
	DBServer() {}
};
DBServer* DBServer::theServer = nullptr;

class Clock
{
private:
	static Clock* theClock;
public:
	static Clock* getInstance()
	{
		if (!theClock) {
			theClock = new Clock;
		}
		return theClock;
	}
};
Clock* Clock::theClock = nullptr;


int main()
{
	Clock::getInstance();
	DBServer::getInstance();

	return 0;
}*/