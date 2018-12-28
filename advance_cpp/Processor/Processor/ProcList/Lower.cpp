/**
 * @file Lower.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Lower.h"
#include <algorithm>
#include <string>


std::string Lower::Processor(const std::string& _str)
{
    std::string temp = _str;     
    std::transform(temp.begin(), temp.end(),
    temp.begin(), ::tolower);
    return temp;
}
