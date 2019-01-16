#ifndef __ISERVER__
#define __ISERVER__

class IAgent;
#include "UncopyAble.h"
#include "IAgent.h"
#include "EventKey.h"

class IServer: private UncopyAble
{
public :
	IServer();
	virtual ~IServer();
	virtual void SubscribeController(IAgent* _agent, const EventKey& _eventkey) = 0;
	//virtual bool PublishEvent(Event _event) = 0;
	virtual void SubscribeSensor(IAgent* _agent, const EventKey& _eventkey) = 0;
};
#endif

