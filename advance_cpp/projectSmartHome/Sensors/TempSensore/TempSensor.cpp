/**
 * @file TempSensor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 * "AMBIENT_TEMP"
 * 
 */

#include "TempSensor.h"
#include "EventKey.h"
#include "Event.h"

TempSensor::TempSensor(const AgentConfig& _agentConfig)
:IAgent(_agentConfig)
{
}

TempSensor::~TempSensor()
{
}

bool TempSensor::Init()
{
	EventKey eventKey(m_agentData.m_type,m_agentData.m_floor,m_agentData.m_room);
	
	//m_agentData.m_server->SubscribeSensor(this, eventKey);
	return true;
}



bool TempSensor::Do()
{
	Event event(m_agentData.m_type,m_agentData.m_floor,m_agentData.m_room);
    event.PrintEvent();
    return true;
}

extern "C" {
	IAgent* Create(const IAgent::AgentConfig& _agentConfig)
	{
		return new TempSensor(_agentConfig);
	}
}
