/**
 * @file IServer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __ISERVER__
#define __ISERVER__

#include <vector>
#include "uncopy.h"
#include "IAgent.h"
#include "EventKey.h"

class IAgent;

class IServer: private Uncopy
{
public:
	virtual ~IServer();
    virtual void Run() = 0;
    virtual void PublishEvent() = 0;
	//for debug
    virtual void Print() = 0;
};
#endif

