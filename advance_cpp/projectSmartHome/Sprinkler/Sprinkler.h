#ifndef __SPRINKLER_H__
#define __SPRINKLER_H__

#include <string>
#include "IAgent.h"


class Sprinkler: public IAgent
{
public:
	Sprinkler();
	virtual ~Sprinkler();
	virtual bool Init(const AgentConfig& _agentConfig);
	//virtual bool Connect();
	// Send event to the agent from the server 
	//virtual bool TakeEvent(const std::string& _eventType);
private:

};

#endif

