/**
 * @file memPage.h
 * @brief 
 * @version 0.1
 * @date 2018-12-04
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __PAGE_H__
#define __PAGE_H__

#include "memManager.h"
using namespace std;



class memPage_t:virtual public memManager_t
{
private:
    static size_t capacity;
    size_t m_capacity;

    memPage_t(memPage_t& _null){}
    memPage_t& operator = (const memPage_t _m);

public:
    ~memPage_t(){}

    memPage_t():memManager_t(capacity),m_capacity(capacity){}

    memPage_t(size_t _capacity):memManager_t(_capacity),m_capacity(_capacity){capacity = m_capacity;}

    static void setNewSize(size_t _newSize){capacity = _newSize;} 

    bool setCurrPos(size_t _memSize);

    size_t getCurrPos();

    bool isEmpty();

    bool isFull();

    size_t  nLeftSize();


    size_t getCapacity(){return m_capacity;}

    size_t  read(void *_buf, size_t _count);

    size_t  read(size_t _pos,void *_buf, size_t _count);

    size_t  write(const void *_buf, size_t _count);

    size_t  write(size_t _pos,const void *_buf, size_t _count);
};




#endif /*__PAGE_H__*/