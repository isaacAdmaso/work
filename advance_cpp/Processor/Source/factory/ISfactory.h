/**
 * @file ISfactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __ISFACTORY_H__
#define __ISFACTORY_H__

class Isource;
class FileIn;
class ConsoleIn;
class Socket;

class ISfactory
{
public:
    // Declare overloads for each kind of a file to dispatch
	virtual Isource* dispatch(FileIn& _source) = 0;
	virtual Isource* dispatch(ConsoleIn& _source) = 0;
	virtual Isource* dispatch(Socket& _source) = 0;
};



#endif //__ISFACTORY_H__