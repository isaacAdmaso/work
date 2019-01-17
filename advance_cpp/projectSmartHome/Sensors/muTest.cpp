#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "IAgent.h"
#include "TempSensor.h"
#include "FireSensor.h"



UNIT(ISENSORETest)
    IAgent::AgentConfig agent1 = {NULL,"ID","fire!!!","fire","1","23","config"} ;
    IAgent::AgentConfig agent2 = {NULL,"ID","its too cold!!!","AC","1","23","config"} ;
    FireSensor sensore1(agent1);
    TempSensor sensore2(agent2);
    sensore1.SendEvent();
    sensore2.SendEvent();

END_UNIT

TEST_SUITE(sensore)
    TEST(ISENSORETest)
END_SUITE
