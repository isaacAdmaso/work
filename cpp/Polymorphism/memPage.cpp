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


void memPage_t::setCurrPos(size_t _memSize)
{
    if(_memSize < m_capacity)
        memManager_t::setCurrPos(_memSize);

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
    size_t cur = (m_capacity - getCurrPos());

    if(_count > ( cur))
        return memManager_t::read(_buf,cur);
    return memManager_t::read(_buf,_count);
    
}
/*
size_t  memPage_t::read(size_t _pos,void *_buf, size_t _count){

}
size_t  memPage_t::write(void *_buf, size_t _count){

}
size_t  memPage_t::write(size_t _pos,void *_buf, size_t _count){

}
*/
