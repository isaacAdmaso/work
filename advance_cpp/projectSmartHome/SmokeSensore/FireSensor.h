#ifndef __FIRESENSOR_H__
#define __FIRESENSOR_H__

#include "IAgent.h"
class FireSensor: public IAgent
{
public:
	FireSensor(const AgentConfig& _agentConfig);
	virtual ~FireSensor();
	virtual bool Init();
	virtual bool Connect();
	// Send event to the agent from the server 
	//virtual bool TakeEvent(const std::string& _eventType);
};
#endif
