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
    static size_t ReadnWrite(void* _buf, size_t _count);
    size_t m_capacity,m_current,m_maxWrite;
    Page_t(Page_t& _null){}
    Page_t& operator = (const Page_t _m);

public:
    ~Page_t(){delete[](char*)m_Ptr;}
    Page_t():m_Ptr(new char[capacity]),m_capacity(capacity),m_current(0),m_maxWrite(0){}
    Page_t(size_t _userSize):m_Ptr(new char[_userSize]),m_capacity(_userSize),m_current(0),m_maxWrite(0){}
    size_t  getCurrPos(){return m_current;}
    bool    setCurrPos(size_t _pos){if(_pos <= m_maxWrite){m_current = _pos;return true;}return false;}
    bool    isEmpty(){return !m_maxWrite;}
    bool    isFull(){return m_maxWrite == m_capacity;}
    size_t  realSize(){return m_maxWrite;}
    size_t  getCapacity(){return m_capacity;}
    size_t  read(void *_buf, size_t _count);
    size_t  read(size_t _pos,void *_buf, size_t _count);
    size_t  write(const void *_buf, size_t _count);
    size_t  write(size_t _pos,const void *_buf, size_t _count);


};



#endif //__PAGE_H__