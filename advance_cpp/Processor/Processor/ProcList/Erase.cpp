/**
 * @file Erase.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <string>
#include <algorithm>
#include "Erase.h"

std::string Erase::helpDelim = "";
bool Erase::toErase(char ch)
{
    return (helpDelim.find(ch) !=std::string::npos);
}

std::string Erase::Processor(const std::string& _str)
{
    helpDelim = m_strDel; 
    std::string temp = _str;
    iter_t begin = temp.begin();
    iter_t it = std::remove_if (temp.begin(), temp.end(), toErase);
    std::string rtVal (begin,it);    
    return rtVal;  
}
