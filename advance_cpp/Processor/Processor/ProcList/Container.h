/**
 * @file Container.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <vector>
#include "ITx.h"


class Container: public ITx
{
private:
    std::vector<ITx*>&  m_container; 
    typedef std::vector<ITx*>::iterator iter_t;

public:
    Container(std::vector<ITx*>& _pVec);
    void AddProc(ITx* _p){m_container.push_back(_p);}
    virtual std::string Processor(const std::string& _str);
};

#endif //__CONTAINER_H__