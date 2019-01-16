#include "Sprinkler.h"
#include "EventKey.h"
Sprinkler::Sprinkler()
{

}
Sprinkler::~Sprinkler()
{
}

bool Sprinkler::Init(const AgentConfig& _agentConfig)
{
	m_id = _agentConfig.m_id;
	m_type = _agentConfig.m_type;
	m_log = _agentConfig.m_log;
	m_floor = _agentConfig.m_floor;
	m_room = _agentConfig.m_room;
	m_server = _agentConfig.m_server;
	
	EventKey eventKey;
	eventKey.m_eventType = "FIRE_DETECTED";
	m_server->SubscribeController(this, eventKey);
	
	eventKey.m_floor = m_floor;
	m_server->SubscribeController(this, eventKey);
	
	if(!(m_room == ""))
	{
		eventKey.m_room = m_room;
		m_server->SubscribeController(this, eventKey);
	}
	return true;
}

extern "C" 
{
IAgent* Create()
{
	return new Sprinkler();
}

}
