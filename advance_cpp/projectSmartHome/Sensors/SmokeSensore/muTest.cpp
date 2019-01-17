#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "IAgent.h"
#include "FireSensor.h"


UNIT(ISENSORETest)
    IAgent::AgentConfig agent = {NULL,"ID","fire!!!","fire","1","23","config"} ;
    FireSensor sensore(agent);
    sensore.SendEvent();

END_UNIT

TEST_SUITE(sensore)
    TEST(ISENSORETest)
END_SUITE
