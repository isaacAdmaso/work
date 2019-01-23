/**
 * @file MyServer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "MyServer.h"

MyServer::MyServer(std::vector<IAgent::AgentConfig>& _agents)
:m_agentManager(_agents,this)
{
}

void MyServer::Print()
{
    m_agentManager.Print();
}

void MyServer::Run()
{
    m_agentManager.Run();
}


extern "C" {
	IServer* CreateServer(void* _agents)
	{
		std::vector<IAgent::AgentConfig>* agents = (std::vector<IAgent::AgentConfig>*) _agents; 
		return new MyServer(*agents);
	}
}
