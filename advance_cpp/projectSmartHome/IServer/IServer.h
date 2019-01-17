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

#include "uncopy.h"
#include "IAgent.h"
#include "EventKey.h"

class IAgent;

class IServer: private Uncopy
{
public :
	IServer();
	virtual ~IServer();
	virtual void SubscribeController(IAgent* _agent, const EventKey& _eventkey) = 0;
	virtual void SubscribeSensor(IAgent* _agent, const EventKey& _eventkey) = 0;
};
#endif

