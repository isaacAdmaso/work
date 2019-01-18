/**
 * @file AgentFactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __AGENTFACTORY__
#define __AGENTFACTORY__
#include <string>
#include "IAgent.h"
#include "IServer.h"
#include "uncopy.h"


class AgentFactory: private Uncopy
{
public:
	~AgentFactory();
	IAgent* MakeAgent(const IAgent::AgentConfig& _agentConfig);

private:
	typedef IAgent* (*Create)(const IAgent::AgentConfig&);
	static const std::string libPrefix;
	static const std::string libSuffix;
	//IServer* m_server;
};

#endif //__AGENTFACTORY__
