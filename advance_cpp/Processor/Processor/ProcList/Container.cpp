/**
 * @file Container.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Container.h"

Container::Container(std::vector<ITx*>& _pVec)
:m_container(_pVec)
{
}


std::string Container::Processor(const std::string& _str)
{
    std::string temp = _str;  
    for(iter_t it = m_container.begin(); it != m_container.end(); ++it)
    {
        temp = (*it)->Processor(temp);
    }
    return temp;
}

