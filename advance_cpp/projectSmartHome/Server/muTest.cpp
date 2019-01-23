#include <iostream>
#include <stdio.h>
#include <vector>
#include "mu_test.h"

#include "MyServer.h"


UNIT(server)
using namespace std;


    IAgent::AgentConfig agent1 = {NULL,"HVAC","AC","AC","1","23","config"};
    IAgent::AgentConfig agent2 = {NULL,"SMOKE","FIRE","AC","1","23","sensor"};
    IAgent::AgentConfig agent3 = {NULL,"SPRINKLER","FIRE","AC","1","23","config"};
    IAgent::AgentConfig agent4 = {NULL,"TEMP","TEMP","AC","1","23","sensor"};
    
    vector<IAgent::AgentConfig> agents;
    
    agents.push_back(agent1);
    agents.push_back(agent2);
    agents.push_back(agent3);
    agents.push_back(agent4);

    MyServer server(agents);
    cout<<endl<<"*****************SERVER RUN************"<<endl;
    server.Run();
    cout<<endl<<"*****************SERVER PRINT************"<<endl;
    server.Print();

END_UNIT

TEST_SUITE(Server)
    TEST(server)
END_SUITE
