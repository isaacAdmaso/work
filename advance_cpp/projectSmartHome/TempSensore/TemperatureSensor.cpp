#include "TemperatureSensor.h"
#include "EventKey.h"
#include "Event.h"

TemperatureSensor::TemperatureSensor(const AgentConfig& _agentConfig)
:IAgent(_agentConfig)
{
//config the line to upper lower and period;
}

TemperatureSensor::~TemperatureSensor()
{
}

bool TemperatureSensor::Init()
{
	EventKey eventKey;
	
	eventKey.m_eventType = "AMBIENT_TEMP";
	eventKey.m_floor = m_floor;
	eventKey.m_room = m_room;
	
	m_server->SubscribeSensor(this, eventKey);
	return true;
}

