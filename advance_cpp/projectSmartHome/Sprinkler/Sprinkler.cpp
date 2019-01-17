#include "Sprinkler.h"
#include "EventKey.h"
Sprinkler::Sprinkler(const AgentConfig& _agentConfig)
:IAgent(_agentConfig)
{

}
Sprinkler::~Sprinkler()
{
}

bool Sprinkler::Init()
{
	EventKey eventKey("FIRE_DETECTED",m_agentData.m_floor,m_agentData.m_room);

	m_agentData.m_server->SubscribeController(this, eventKey);

	return true;
	
}

extern "C" 
{
IAgent* Create(const IAgent::AgentConfig& _agentConfig)
{
	return new Sprinkler(_agentConfig);
}

}
