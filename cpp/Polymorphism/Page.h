/**
 * @file Page.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-05
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __PAGE_H__
#define __PAGE_H__

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "Manager.h"

using namespace std;



class Page_t
{
private:
    void* m_Ptr;
    static size_t capacity;
    size_t m_capacity;
    Page_t(Page_t& _null){}
    Page_t& operator = (const Page_t _m);

public:
    ~Page_t(){delete[](char*)m_Ptr;}
    Page_t():m_Ptr(new char[capacity]),m_capacity(capacity){}
    Page_t(size_t _userSize):m_Ptr(new char[_userSize]),m_capacity(_userSize){}


};



#endif //__PAGE_H__