/**
 * @file Auto_Ptr.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 * ************************with exclusive ownership************************
 */
#ifndef __AUTO_PTR_H__
#define __AUTO_PTR_H__
#include <iostream>


template<class T>
class Auto_Ptr
{
public:
    Auto_Ptr(T* _pointer = nullptr);
    Auto_Ptr(int& intRf);
    Auto_Ptr(const Auto_Ptr& _pointer );
    ~Auto_Ptr();
    Auto_Ptr& operator=(Auto_Ptr& _pointer );
    T& operator*();
    const T& operator*()const;
    T* operator->();
    const T* operator->() const;
    operator const void*() const; 
private:
    T* HelperSwap();
private:
    T* m_ptr;
};

template<class T>
Auto_Ptr<T>::Auto_Ptr(T*_pointer)
:m_ptr(_pointer)
{
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(int& intPtr)
:m_ptr(&intPtr)
{
}

template<class T>
Auto_Ptr<T>::Auto_Ptr(const Auto_Ptr& _pointer )
:m_ptr(_pointer.m_ptr)
{
}

template<class T>
Auto_Ptr<T>::~Auto_Ptr()
{
    if(m_ptr)
        delete m_ptr;
}

template<class T>
Auto_Ptr<T>& Auto_Ptr<T>::operator=(Auto_Ptr& _pointer )
{
    if(*this != _pointer)
    {
        if(m_ptr)
            delete m_ptr;
        m_ptr = _pointer.m_ptr;
        _pointer.m_ptr = nullptr;
    }
    return *this;
}

template<class T>
T* Auto_Ptr<T>::HelperSwap()
{
    T* temp = m_ptr;
    m_ptr = nullptr;
    return temp;
}

template<class T>
T& Auto_Ptr<T>::operator*()
{
    T* temp = HelperSwap();
    return *temp;
}

template<class T>
const T& Auto_Ptr<T>::operator*()const
{
    T* temp = HelperSwap();
    return *temp;
}

template<class T>
T* Auto_Ptr<T>::operator->()
{
    return HelperSwap();
}
template<class T>
const T* Auto_Ptr<T>::operator->() const
{
    return HelperSwap();
}

template<class T>
Auto_Ptr<T>::operator const void*() const
{
    return (const void*) HelperSwap();
}

class Temp
{
public:
    void foo(){std::cout<<"in Temp class in foo "<<std::endl;}
};
int main(int argc, char const *argv[])
{
using namespace std;

    //Auto_Ptr <int> p1 = new int(5);
    //cout<<endl<<*p1<<endl;
    Auto_Ptr <Temp> p1 = new Temp;
    p1->foo();
    return 0;
}

#endif //__AUTO_PTR_H__