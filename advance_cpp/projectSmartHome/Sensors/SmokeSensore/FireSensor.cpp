/**
 * @file FireSensor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
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
	EventKey eventKey(m_agentData.m_type,m_agentData.m_floor,m_agentData.m_room);
	
	m_agentData.m_server->SubscribeSensor(this, eventKey);
	return true;
}


bool FireSensor::SendEvent()
{
	Event event(m_agentData.m_type,m_agentData.m_floor,m_agentData.m_room);
    event.PrintEvent();
    return true;
}
