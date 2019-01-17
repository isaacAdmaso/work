#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "IAgent.h"
#include "TempSensor.h"


UNIT(ISENSORETest)
    IAgent::AgentConfig agent = {NULL,"ID","its too cold!!!","AC","1","23","config"} ;
    TempSensor sensore(agent);
    sensore.SendEvent();

END_UNIT

TEST_SUITE(sensore)
    TEST(ISENSORETest)
END_SUITE
