/**
 * @file Dfactory.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-29
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include "Dfactory.h"
#include "Console.h"
#include "FileOut.h"
#include "Container.h"

Idest*  Dfactory ::GetFile(const std::string& _FileN)
{
    FileOut* rtVal = new  FileOut(_FileN);
    //if (rtVal.is_open()) {
        return rtVal;
}

Idest*  Dfactory ::GetConsole()
{
    return new Console(std::cout);
}

Idest*    Dfactory::GetContainer()
{
    return  new Container(); 
}
