/**
 * @file Console.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <ostream>
#include "Console.h"


Console::Console(std::ostream& _cout)
:m_console(_cout)
{

}
void Console::PutString(const std::string& _str)
{
    m_console << _str<<" ";
    m_console.flush();

}
