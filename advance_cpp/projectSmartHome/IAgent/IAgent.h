/**
 * @file IAgent.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-16
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __IAGENT_H__
#define __IAGENT_H__

#include <iostream>
#include <string>
#include "IServer.h"
#include "uncopy.h"

class IServer;

class IAgent: private Uncopy
{
public:
	typedef struct AgentConfig
	{
		IServer*		m_server;
		std::string		m_id;
		std::string		m_type;
		std::string		m_log;
		std::string		m_floor;
		std::string		m_room;
		std::string		m_configData;
	}AgentConfig;

public:
	IAgent();
	IAgent(const AgentConfig& _agentConfig);
	virtual ~IAgent();
	virtual bool Init() = 0;
	virtual bool Do() = 0;
//protected:
	AgentConfig m_agentData;
	std::string m_config;

};

std::ostream&    operator << (std::ostream& _os,const IAgent::AgentConfig& _s);


#endif
