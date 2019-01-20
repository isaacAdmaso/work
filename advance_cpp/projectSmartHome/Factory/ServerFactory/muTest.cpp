#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "IAgent.h"
#include "AgentFactory.h"

/*
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

*/
UNIT(FACTORY)
using namespace std;

    AgentFactory af;

    IAgent::AgentConfig agent1 = {NULL,"HVAC","AC","AC","1","23","config"};
    IAgent::AgentConfig agent2 = {NULL,"SMOKE","FIRE","AC","1","23","config"};
    IAgent::AgentConfig agent3 = {NULL,"SPRINKLER","FIRE","AC","1","23","config"};
    IAgent::AgentConfig agent4 = {NULL,"TEMP","TEMP","AC","1","23","config"};
    IAgent* sensore1 = af.MakeAgent(agent1);
    IAgent* sensore2 = af.MakeAgent(agent2);
    IAgent* sensore3 = af.MakeAgent(agent3);
    IAgent* sensore4 = af.MakeAgent(agent4);
    cout <<endl<<endl<< "****HVAC****"<<endl<<endl;
    sensore1->Do();
    cout <<endl<<endl<< "****SMOKE****"<<endl<<endl;
    sensore2->Do();
    cout <<endl<<endl<< "****SPRINKLER*****"<<endl<<endl;
    sensore3->Do();
    cout <<endl<<endl<< "****TEMP****"<<endl<<endl;
    sensore4->Do();

END_UNIT

TEST_SUITE(sensore)
    TEST(FACTORY)
END_SUITE
