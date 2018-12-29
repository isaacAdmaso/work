/**
 * @file Dfactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-29
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __DFACTORY_H__
#define __DFACTORY_H__

#include "Console.h"
#include "FileOut.h"



class Dfactory
{
public:
    FileOut*    GetFile(const std::string& _FileN);
    Console*    GetConsole();
};

#endif //__DFACTORY_H__