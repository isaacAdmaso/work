#include "FireSensor.h"
#include "EventKey.h"
#include "Event.h"

FireSensor::FireSensor(const AgentConfig& _agentConfig)
:IAgent(_agentConfig)
{
}

FireSensor::~FireSensor()
{
}

bool FireSensor::Init()
{
	EventKey eventKey;
	
	eventKey.m_eventType = "FIRE_DETECTED";
	eventKey.m_floor = m_floor;
	eventKey.m_room = m_room;
	
	m_server->SubscribeSensor(this, eventKey);
}

bool FireSensor::Connect()
{
	Event event;
	
	event.m_key.m_eventType = "FIRE_DETECTED";
	event.m_key.m_floor = m_floor;
	event.m_key.m_room = m_room;
	event.m_time = "time maker";
	//send messageQ
	
}
