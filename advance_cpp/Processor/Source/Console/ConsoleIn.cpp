/**
 * @file ConsoleIn.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <istream>
#include "ConsoleIn.h"

ConsoleIn::ConsoleIn(std::istream& _cin)
:m_console(_cin)
{
}

std::string ConsoleIn::GetString()
{
    std::string tempLine;
    std::getline (m_console,tempLine);
    if(tempLine == "break")
        tempLine = "";  
    return tempLine;
}

void ConsoleIn::accept(ISfactory  &dispatcher)
{
    dispatcher.dispatch(*this);
}
