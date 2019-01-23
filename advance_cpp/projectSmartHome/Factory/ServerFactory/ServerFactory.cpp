/**
 * @file ServerFactory.cpp
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

IServer* ServerFactory::MakeServer(const std::string& _lib ,std::vector<IAgent::AgentConfig>& _agents)
{
	CreateServer createServer;

	void* handle = dlopen(_lib.c_str(), RTLD_LAZY);
	std::cout<<dlerror()<<std::endl;
	createServer = (CreateServer)dlsym(handle, "CreateServer");
	IServer* Server = createServer((void*)&_agents);
	return Server;
}
