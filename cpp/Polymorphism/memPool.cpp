/**
 * @file memPool.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-05
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "memPool.h" 

int memPool_t::nPagesToBegin = 1;


void memPool_t::setCurrPos(size_t _memSize)
{
    int pSize = 0;
    vector<memPage_t*>::iterator it = m_vec.begin();


    for (; it != m_vec.end(); ++it)
    {
        if(pSize > _memSize)
        {
            (*it)->setCurrPos(_memSize);
        }
        pSize = (*it)->getCapacity();
        _memSize -= pSize;
    }
}


size_t memPool_t::getCurrPos()
{
    return ((m_vec.end())->getCurrPos() * m_vec.size());
}

