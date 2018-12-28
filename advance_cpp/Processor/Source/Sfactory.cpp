/**
 * @file Sfactory.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include "Sfactory.h"

FileIn*     Sfactory::GetFile(const std::string& _FileN)
{
    return new  FileIn(_FileN);
}
ConsleIn*   Sfactory::GetConsole()
{
    return new ConsleIn(std::cin);
}
    