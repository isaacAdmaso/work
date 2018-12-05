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
    size_t inPage;
    void inline createFrom(size_t _pageSize);
    memPool_t(memPool_t& _p){}
    memPool_t& operator = (const memPool_t _m);


public:
    ~memPool_t();
    memPool_t(){createFrom();}
    memPool_t(size_t _pageSize){createFrom(_pageSize);}

    bool setCurrPos(size_t _memSize);

    size_t getCurrPos();
   
    bool isEmpty(){return m_vec[0]->isEmpty();}

    size_t  realSize();
  
    size_t  read(void *_buf, size_t _count);

    size_t  read(size_t _pos,void *_buf, size_t _count);
    
    size_t  write(const void *_buf, size_t _count);
    
    size_t  write(size_t _pos,const void *_buf, size_t _count);
};

void inline memPool_t::createFrom(void)
{
    memPage_t* pg = new memPage_t;
	m_vec.insert(m_vec.end(), pg);
    inPage = 0;
}

void inline memPool_t::createFrom(size_t _pageSize)
{
    memPage_t* pg = new memPage_t(_pageSize);
	m_vec.insert(m_vec.end(), pg);
    inPage = 0;
}


#endif //__POOL_H__