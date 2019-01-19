/**
 * @file SmartHome.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include "SmartHome.h"
#include "Reader.h"

void SmartHome::Print()
{
    int line = 0;
    for (std::vector<std::string>::const_iterator i = m_configVec.begin();\
    i != m_configVec.end(); ++i)
    {
        std::cout<<std::endl <<"************agent: "<< line++<<"*************" <<std::endl;
        std::cout << *i << ' ';
    }
    std::cout<<std::endl;
}

SmartHome::SmartHome(const std::string& configPath)
{
    Reader sh1(configPath,m_configVec);
    Print();

}