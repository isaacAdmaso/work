/**
 * @file IHandler.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __AGENTMAN_H__
#define __AGENTMAN_H__

#include <vector>
#include "uncopy.h"
#include "IAgent.h"
#include "ControllerHandler.h"
#include "SensorHandler.h"

class AgentHandler:private Uncopy
{
public:
    AgentHandler(std::vector<IAgent::AgentConfig>& _agentsInput);
    void Run();
    void Print();
private:
	ControllerHandler m_controllerHandler;
	SensorHandler m_sensorHandler;
};

#endif //__AGENTMAN_H__