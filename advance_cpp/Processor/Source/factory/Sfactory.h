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

#include "Isource.h"


class Sfactory
{
public:

    Isource*    GetFile(const std::string& _FileN);
    Isource*    GetConsole();
    //SocketIn*
};



#endif //__SFACTORY_H__