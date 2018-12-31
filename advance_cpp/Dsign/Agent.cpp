/**
 * @file Agent.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <vector>
#include <iostream>
#include "Agent.h"

void Agent::Goal()
{
    iter_t curr =  m_trv.begin(), end = m_trv.end();

    for(; curr != end; ++curr)
    {
        std::cout<<"what you want?"<<std::endl;
        (*curr)->Goal();
    }
}

Agent::~Agent()
{
    m_trv.clear();
}

void Agent::AddTrav(Irole* trv)
{
    m_trv.push_back(trv);
}