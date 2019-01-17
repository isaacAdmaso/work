#include <iostream>
#include <stdio.h>
#include <dlfcn.h>
#include "mu_test.h"

#include "IAgent.h"



UNIT(ISENSORETest)
typedef IAgent* (*Create)(const IAgent::AgentConfig&);
    
    Create funPtr;
    void* handle;
    handle = dlopen("../../lib/libTEMP.so", RTLD_LAZY);
    funPtr = (Create)dlsym(handle, "Create");

    IAgent::AgentConfig agent = {NULL,"ID","fire!!!","fire","1","23","config"} ;
    IAgent* sensor = funPtr(agent);

    sensor->Do();

END_UNIT

TEST_SUITE(sensore)
    TEST(ISENSORETest)
END_SUITE
