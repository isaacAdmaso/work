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
#include "Container.h"

void Container::PutString(const std::string& _str)
{
    my_Container.push_back(_str);
}


void Container::PrintC()
{
    for (std::vector<std::string>::const_iterator i = my_Container.begin();\
    i != my_Container.end(); ++i)
        std::cout << *i << ' ';
}

