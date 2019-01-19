/**
 * @file Container.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "VContainer.h"

void VContainer::PutString(const std::string& _str)
{
    my_Container.push_back(_str);
}


void VContainer::PrintC()
{
    int line = 0;
    for (std::vector<std::string>::const_iterator i = my_Container.begin();\
    i != my_Container.end(); ++i)
    {
        std::cout<<std::endl <<"************agent: "<< line++<<"*************" <<std::endl;
        std::cout << *i << ' ';
    }
}

