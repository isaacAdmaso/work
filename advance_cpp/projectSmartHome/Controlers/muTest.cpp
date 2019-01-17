#include <iostream>
#include <stdio.h>
#include <dlfcn.h>
#include "mu_test.h"

#include "IAgent.h"



UNIT(IcontrolerTest)
typedef IAgent* (*Create)(const IAgent::AgentConfig&);

    Create funPtr;
    void* handle;
    handle = dlopen("../lib/libSPRINKLER.so", RTLD_LAZY);
    funPtr = (Create)dlsym(handle, "Create");

    IAgent::AgentConfig agent1 = {NULL,"ID","fire!!!","fire","1","23","config"} ;
    IAgent* sensore1 = funPtr(agent1);
    handle = dlopen("../lib/libHVAC.so", RTLD_LAZY);
    funPtr = (Create)dlsym(handle, "Create");
    IAgent::AgentConfig agent2 = {NULL,"ID","its too cold!!!","AC","1","23","config"} ;
    IAgent* sensore2 = funPtr(agent2);
    sensore1->Do();
    sensore2->Do();

END_UNIT

TEST_SUITE(sensore)
    TEST(IcontrolerTest)
END_SUITE
