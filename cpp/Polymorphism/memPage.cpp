/**
 * @file memPage.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-04
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "memPage.h"

size_t memPage_t::capacity = 6;


bool memPage_t::setCurrPos(size_t _memSize)
{
    if(_memSize < m_capacity)
        return memManager_t::setCurrPos(_memSize);
    return false;
}

size_t memPage_t::getCurrPos(){
    return memManager_t::getCurrPos();
}

bool memPage_t::isEmpty(){
    return memManager_t::isEmpty();
}

bool memPage_t::isFull(){
    return memManager_t::isFull();
}

size_t  memPage_t::nLeftSize()
{
    return  memManager_t::nLeftSize();
}

size_t  memPage_t::read(void *_buf, size_t _count)
{
    int cur = (m_capacity - getCurrPos());
    
    if(cur < 0)
        return 0;

    if(_count >(size_t) cur)
        return memManager_t::read(_buf,cur);
    
    return memManager_t::read(_buf,_count);
}

size_t  memPage_t::read(size_t _pos,void *_buf, size_t _count)
{
    size_t cur = (m_capacity - _pos);

    if(_pos > m_capacity)
        return 0;

    setCurrPos(_pos);
    
    if(_count > cur)
        return memManager_t::read(_buf,cur);
    
    return memManager_t::read(_buf,_count);
}

size_t  memPage_t::write(const void *_buf, size_t _count)
{
    int cur = (m_capacity - getCurrPos());
    
    if(cur <= 0)
        return 0;

    if(_count > (size_t)cur)
        return memManager_t::write(_buf, cur);
    
    return memManager_t::write(_buf, _count);

}

size_t  memPage_t::write(size_t _pos,const void *_buf, size_t _count)
{
    size_t cur = (m_capacity - _pos);

    if(_pos > m_capacity)
        return 0;

    setCurrPos(_pos);
    
    if(_count > cur)
        return memManager_t::write(_buf,cur);
    
    return memManager_t::write(_buf, _count);
}
