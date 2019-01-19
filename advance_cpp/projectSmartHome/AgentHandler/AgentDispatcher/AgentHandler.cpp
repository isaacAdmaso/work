/**
 * @file AgentHandler.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "AgentFactory.h"
#include "AgentHandler.h"
#include "EventKey.h"


AgentHandler::AgentHandler(std::vector<IAgent::AgentConfig>& _agentsInput)
{
    AgentFactory af;
    std::string sensor = "sensor";

    for (std::vector<IAgent::AgentConfig>::const_iterator i = _agentsInput.begin();\
    i != _agentsInput.end(); ++i)
    {
        EventKey key(i->m_type,i->m_floor,i->m_room);
        IAgent* newAgent = af.MakeAgent(*i);
        if((i->m_configData).find(sensor) != std::string::npos)
        {
            m_sensorHandler.Insert(newAgent,key);
        }
        else
        {
            m_controllerHandler.Insert(newAgent,key);
        }
    }

}

void AgentHandler::Print()
{
    std::cout << "*******SENSORS******"<<std::endl;
    m_sensorHandler.Print();
    std::cout << "*******CONTROLER******"<<std::endl;
    m_controllerHandler.Print();

}