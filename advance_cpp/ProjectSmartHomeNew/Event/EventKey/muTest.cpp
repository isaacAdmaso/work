#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "EventKey.h"


UNIT(EkeyTest)
    EventKey smoke,fire("fire",Location(6,1));
    
    fire.PrintEvent();
    smoke.SetEvent("smoke",Location(3,2));
    smoke.PrintEvent();
    std::cout <<std::endl<< (fire < smoke )<<std::endl;

END_UNIT

TEST_SUITE(key)
    TEST(EkeyTest)
END_SUITE
