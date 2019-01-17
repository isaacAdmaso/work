#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "IAgent.h"
#include "ISensore.h"


UNIT(ISENSORETest)
    IAgent::AgentConfig agent = {NULL,"ID","ISENSORE","Isens","1","23","config"} ;
    ISensore sensore(agent);
    sensore.SendEvent();

END_UNIT

TEST_SUITE(sensore)
    TEST(ISENSORETest)
END_SUITE
