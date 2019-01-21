/**
 * @file Shared_ptr.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * 
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__

class RefCounter
{
public:
    RefCounter(int _n){m_count = _n;}
    void    Increment(){++m_count;}
    int     Decrement(){return --m_count;}
    void    Re(){m_count = 0;}
private:
    int m_count;
};


template<class T>
class Shared_ptr
{
public:
    Shared_ptr(T* _pointer = nullptr);
    Shared_ptr(const Shared_ptr& s_pointer );
    ~Shared_ptr();
    T& operator*();
    T* operator->();
    Shared_ptr& operator=(const Shared_ptr& _pointer );
    const T& operator*()const;
    const T* operator->() const;
    operator const void*() const;
private:
    T*          m_pointer;
    RefCounter* m_rC;
};



template <class T>
Shared_ptr<T>::Shared_ptr(T* _pointer)
:m_pointer(_pointer)
{
    if(_pointer)
    {
        m_rC = new RefCounter(1);
    }
    else
    {
        m_rC = nullptr;
    }
    
}



template <class T>
Shared_ptr<T>::Shared_ptr(const Shared_ptr& s_pointer)
:m_pointer(s_pointer.m_pointer),m_rC(s_pointer.m_rC)
{
    if(m_rC)
        m_rC->Increment();
}



template <class T>
Shared_ptr<T>::~Shared_ptr()
{
    if(!(m_rC->Decrement()))
    {
        delete m_pointer;
        delete m_rC;
    }
}


template <class T>
T& Shared_ptr<T>::operator*()
{
    T* temp = m_pointer;
    if(!m_pointer)
    {
        temp = new T;
        m_rC      = new RefCounter(1);
    }
    else if(!(m_rC->Decrement()))
    {
        m_rC->Increment();
    }
    else
    {
        temp = new T(*m_pointer);
        m_rC = new RefCounter(1);
    }
    m_pointer = temp;
    return *m_pointer;
}



template <class T>
T* Shared_ptr<T>::operator->()
{
    T* temp = m_pointer;
    if(!m_pointer)
    {
        temp = new T;
        m_rC = new RefCounter(1);
    }
    else if(!(m_rC->Decrement()))
    {
        m_rC->Increment();
    }
    else
    {
        temp = new T(*m_pointer);
        m_rC = new RefCounter(1);
    }
    m_pointer = temp;
    return m_pointer;
}



template <class T>
Shared_ptr<T>& Shared_ptr<T>::operator=(const Shared_ptr& _pointer )
{
    if(*this != _pointer)
    {
        if((m_pointer) && !((m_rC->Decrement())))
        {
            delete m_pointer;
            delete m_rC;
        }
        m_pointer = _pointer.m_pointer;
        m_rC      = _pointer.m_rC; 
        if(m_rC)
            m_rC->Increment();
    }
    return *this;
}



template <class T>
const T& Shared_ptr<T>::operator*() const
{
    return m_pointer;
}



template <class T>
const T* Shared_ptr<T>::operator->() const
{
    return m_pointer;
}



template <class T>
Shared_ptr<T>::operator const void*() const
{
    return (const void*)m_pointer;    
}

#endif //__SHAREDPTR_H__