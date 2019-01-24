/**
 * @file HVAC.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream> //for debug
#include "HVAC.h"
#include "EventKey.h"

HVAC::HVAC(const AgentConfig& _agentConfig)
:IAgent(_agentConfig)
{
}

HVAC::~HVAC()
{
}

bool HVAC::Init()
{
	EventKey eventKey(m_agentData.m_type,m_agentData.m_floor,m_agentData.m_room);

	//m_agentData.m_server->SubscribeController(this, eventKey);

	return true;
}

bool HVAC::Do()
{
	EventKey eventKey(m_agentData.m_type,m_agentData.m_floor,m_agentData.m_room);
	eventKey.PrintEvent();
	return true;
}

extern "C" {
	IAgent* Create(const IAgent::AgentConfig& _agentConfig)
	{
		return new HVAC(_agentConfig);
	}
}
