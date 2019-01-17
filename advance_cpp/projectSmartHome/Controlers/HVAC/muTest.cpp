#include <iostream>
#include <stdio.h>
#include <dlfcn.h>
#include "mu_test.h"

#include "IAgent.h"




UNIT(IcontrolerTest)
typedef IAgent* (*Create)(const IAgent::AgentConfig&);

    Create funPtr;
    void* handle;
    handle = dlopen("../../lib/libHVAC.so", RTLD_LAZY);
    funPtr = (Create)dlsym(handle, "Create");
    
    IAgent::AgentConfig agent = {NULL,"ID","its too cold!!!","AC","1","23","config"} ;

    IAgent* sensor = funPtr(agent);


    sensor->Do();

END_UNIT

TEST_SUITE(CONTROLER)
    TEST(IcontrolerTest)
END_SUITE
