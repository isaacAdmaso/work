/**
 * @file IAgent.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-08
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __IAGENT_H__
#define __IAGENT_H__
#include <string>
#include <vector>
#include "EventKey.h"




struct AgentConfig
{
    std::string   m_id;
    std::string   m_room;
    std::string   m_floor;
    std::string   m_type;
    std::string   m_configData;
};


class IAgent
{
public:
    static   IAgent*      Create();
    virtual  void         Destroy() = 0;
    virtual  bool         Init( const AgentConfig& _configData ) = 0;
        // Run device, called when server turned on.
    virtual  bool         Connect() = 0;
        // Send event to the agent from the server 
    virtual  bool         GetEvent( const std::string& _eventType ) = 0;
private:
        AgentConfig                agentData;
        std::vector<EventKey>      m_subcribeEvents;
private:
        IAgent();
        virtual               ~IAgent() = 0;
};


#endif //__IAGENT_H__