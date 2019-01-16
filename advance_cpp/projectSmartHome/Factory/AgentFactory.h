#ifndef __AGENTFACTORY__
#define __AGENTFACTORY__

#include "IServer.h"
#include "IAgent.h"
class AgentFactory: private UncopyAble
{
public :
	AgentFactory(IServer* _server);
	~AgentFactory();
	IAgent* MakeAgent(const IAgent::AgentConfig& _agentConfig);
private:
	IServer* m_server;
	//messageQ;
};
#endif
