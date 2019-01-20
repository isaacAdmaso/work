/**
 * @file AgentFactory.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-17
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "ServerFactory.h"
#include <dlfcn.h>
#include <string>


ServerFactory::~ServerFactory()
{
}
IAgent* AgentFactory::MakeAgent(const IAgent::AgentConfig& _agentConfig)
{
	Create createAgent;
	std::string libPath = libPrefix + _agentConfig.m_id + libSuffix;

	void* handle = dlopen(libPath.c_str(), RTLD_LAZY);
	createAgent = (Create)dlsym(handle, "Create");
	IAgent* agent = createAgent(_agentConfig);
	//agent->Init();
	return agent;
}
