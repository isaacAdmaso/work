/**
 * @file IAgent.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "IAgent.h"


IAgent::IAgent()
{
}

IAgent::IAgent(const AgentConfig& _agentConfig)
:m_agentData(_agentConfig)
{
}

IAgent::~IAgent()
{
}
