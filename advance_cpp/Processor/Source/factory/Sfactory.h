/**
 * @file Sfactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __SFACTORY_H__
#define __SFACTORY_H__

#include "ConsoleIn.h"
#include "FileIn.h"


class Sfactory
{
public:
    FileIn*     GetFile(const std::string& _FileN);
    ConsoleIn*   GetConsole();
    //SocketIn*
    
};



#endif //__SFACTORY_H__