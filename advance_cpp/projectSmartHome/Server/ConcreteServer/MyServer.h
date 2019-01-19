/**
 * @file MyServer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __MYSERVER__
#define __MYSERVER__

#include "IServer.h"
#include "ControllerHandler.h"
#include "SensorHandler.h"

class MyServer: public IServer
{
public:
	MyServer();
	virtual ~MyServer();
	virtual void SubscribeController(IAgent* _agent, const EventKey& _eventkey);
	virtual void SubscribeSensor(IAgent* _agent, const EventKey& _eventkey);
private:
	ControllerHandler m_controllerHandler;
	SensorHandler m_sensorHandler;
};
#endif
