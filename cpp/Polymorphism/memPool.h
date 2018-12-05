/**
 * @file memPool.h
 * @brief 
 * @version 0.1
 * @date 2018-12-05
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __POOL_H__
#define __POOL_H__

#include "memPage.h"
#include "memManager.h"

#include <vector>
#include <iostream>

using namespace std;



class memPool_t:virtual public memManager_t
{
private:
    vector<memPage_t*> m_vec;
    void inline createFrom(void);
    int nPages;
    static int nPagesToBegin;
    memPool_t(memPool_t& _p){}

public:
    ~memPool_t();
    memPool_t(){createFrom();}

    void setCurrPos(size_t _memSize);

    size_t getCurrPos();

    bool isEmpty(){return m_StartPos == m_maxWritten;}
    bool isFull(){return (m_StartPos+m_size) == m_maxWritten;}
    size_t  nLeftSize(){return (m_size - (m_maxWritten - m_StartPos));}
    size_t  read(void *_buf, size_t _count);
    size_t  read(size_t _pos,void *_buf, size_t _count);
    size_t  write(void *_buf, size_t _count);
    size_t  write(size_t _pos,void *_buf, size_t _count);

};

void inline memPool_t::createFrom(void)
{
    memPage_t* pg = new memPage_t;
	m_vec.insert(m_vec.end(), pg);	    
}




#endif //__POOL_H__