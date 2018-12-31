/**
 * @file Agent.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __AGENT_H__
#define __AGENT_H__
#include <vector>
#include "Irole.h"

class Agent:public Irole
{
private:
    typedef std::vector<Irole*>::iterator iter_t;
    std::vector<Irole*> m_trv;
public:
    ~Agent();
    void Goal();
    void AddTrav(Irole* trv);
};



#endif //__AGENT_H__