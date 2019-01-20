/**
 * @file Shared_ptr.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__
#include <iostream>

template<class T>
class RefCounter
{
public:
    RefCounter(T* _ptr);
    ~RefCounter();
    int  Increment(){count++; return count;}
    int  Decrement(){Destroy(); return count;}
    T& operator*();
    RefCounter& operator=(RefCounter& _rc );
    const T& operator*() const;
    T* operator->();
    const T* operator->() const;
    operator const void*() const;
private:
    void Destroy();
    T* m_ptr;
    int count;
};

void print(int _count)
{
    //std::cout<< std::endl<<_count<<std::endl;
}

template<class T>
RefCounter<T>::RefCounter(T* _ptr)
{
    if(_ptr)
    {
        count = 1;
        m_ptr = _ptr;
    }
    else
    {
        count = 0;
        m_ptr = nullptr;
    }
    print(count);
};

template<class T>
void RefCounter<T>::Destroy()
{
    count -= 1;
    if((0 >= count) && (m_ptr))
    {
        delete m_ptr;
        m_ptr = nullptr;
    }
    print(count);
};

template<class T>
RefCounter<T>::~RefCounter()
{
    Destroy();
};

template<class T>
T& RefCounter<T>::operator*()
{
    T* temp = nullptr;
    if(m_ptr)
    {
        temp = new T;
        *temp = *m_ptr;
    }
    print(count);
    return *temp; 
};

template<class T>
const T& RefCounter<T>::operator*()const
{
    print(count);
    return m_ptr;
};

template<class T>
T* RefCounter<T>::operator->()
{
    T* temp = nullptr;
    if(m_ptr)
    {
        temp = new T;
        *temp = *m_ptr;
    }
    print(count);
    return temp; 
};

template<class T>
RefCounter<T>& RefCounter<T>::operator=(RefCounter<T>& _rc )
{
    Destroy();
    m_ptr = _rc.m_ptr;
    count = _rc.count;
    count++;  
    return this;  
}


template<class T>
const T* RefCounter<T>::operator->() const
{
    print(count);
    return m_ptr;
};

template<class T>
RefCounter<T>::operator const void*() const
{
    print(count);
    return (const void*)m_ptr ;
};


template<class T>
class Shared_ptr
{
public:
    ~Shared_ptr();
    Shared_ptr(T* _pointer = nullptr);
    Shared_ptr(const Shared_ptr& _pointer );
    Shared_ptr& operator=(Shared_ptr& _pointer );
    T& operator*();
    const T& operator*()const;
    T* operator->();
    const T* operator->() const;
    operator const void*() const;
    void swap(Shared_ptr& _pointer);
private:
    RefCounter<T>* _rC;
};

template<class T>
void Shared_ptr<T>::swap(Shared_ptr<T>& _pointer)
{
    RefCounter<T>* temp = _rC;
    _rC = _pointer._rC;
    _pointer._rC = temp;

} 


template <class T>
Shared_ptr<T>::Shared_ptr(T* _pointer)
{
    _rC = new RefCounter<T>(_pointer);
};

template <class T>
Shared_ptr<T>::~Shared_ptr()
{
    _rC->Decrement();
};

template <class T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr& _pointer )
{
    _rC = _pointer._rC;
    _rC->Increment();
};

template <class T>
Shared_ptr<T>& Shared_ptr<T>::operator=(Shared_ptr& _pointer )
{
    _rC->Decrement();
    _rC = _pointer._rC;
    return *this;
};

template <class T>
T& Shared_ptr<T>::operator*()
{
    return _rC->operator*();
};

template <class T>
const T& Shared_ptr<T>::operator*() const
{
    return _rC->operator*();
};

template <class T>
T* Shared_ptr<T>::operator->()
{
    return _rC->operator->();
};

template <class T>
const T* Shared_ptr<T>::operator->() const
{
    return _rC->operator->();
};

template <class T>
Shared_ptr<T>::operator const void*() const
{
    return _rC->operator const void*();    
};

#endif //__SHAREDPTR_H__