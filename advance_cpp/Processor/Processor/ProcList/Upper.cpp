/**
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <algorithm>
#include <string>
#include "Upper.h"


std::string Upper::Processor(const std::string& _str)
{
    std::string temp = _str;     
    std::transform(temp.begin(), temp.end(),
    temp.begin(), ::toupper);
    return temp;
}
