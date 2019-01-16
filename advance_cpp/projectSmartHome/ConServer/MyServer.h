#ifndef __MYSERVER__
#define __MYSERVER__

#include "IServer.h"
#include "ControllerHandler.h"
#include "SensorHandler.h"

class MyServer: public IServer
{
public :
	MyServer();
	virtual ~MyServer();
	//virtual bool PublishEvent(const Event& _event);
	virtual void SubscribeController(IAgent* _agent, const EventKey& _eventkey);
	virtual void SubscribeSensor(IAgent* _agent, const EventKey& _eventkey);
private:
	ControllerHandler m_controllerHandler;
	SensorHandler m_sensorHandler;
	//lisener
};
#endif
