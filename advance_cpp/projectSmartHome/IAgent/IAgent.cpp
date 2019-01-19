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
#include <iostream>
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

std::ostream&    operator << (std::ostream& _os,const IAgent::AgentConfig& _s)
{
    _os <<  "id " <<_s.m_id<<std::endl <<\
            "type " <<_s.m_type<<std::endl << \
            "log " <<_s.m_log<<std::endl << \
            "floor " <<_s.m_floor<<std::endl << \
            "room " <<_s.m_room<<std::endl << \
            "configData " <<_s.m_configData<<std::endl;
    return _os;
}
