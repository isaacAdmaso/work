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

const std::string MyServer::msg_name = "/MSGQ"; 


MyServer::MyServer(std::vector<IAgent::AgentConfig>& _agents)
:m_agentManager(_agents,this),m_msgq(msg_name)
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

void MyServer::PublishEvent()
{

}

extern "C" {
	IServer* CreateServer(void* _agents)
	{
		std::vector<IAgent::AgentConfig>* agents = (std::vector<IAgent::AgentConfig>*) _agents; 
		return new MyServer(*agents);
	}
}
