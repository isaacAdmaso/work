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
// class Sfactory: public ISfactory
// {
// public:
//     virtual Isource* dispatch(FileIn& _source);
//     virtual Isource* dispatch(ConsoleIn& _source);
//     virtual Isource* dispatch(Socket& _source);
// };



#endif //__SFACTORY_H__