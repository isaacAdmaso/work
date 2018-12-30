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
#include "ConsoleIn.h"
#include "FileIn.h"


Isource*     Sfactory::GetFile(const std::string& _FileN)
{
    FileIn* rtVal = new  FileIn(_FileN);
    //if (rtVal.is_open()) {
        return rtVal;
}
Isource*    Sfactory::GetConsole()
{
    return new ConsoleIn(std::cin);
}
    