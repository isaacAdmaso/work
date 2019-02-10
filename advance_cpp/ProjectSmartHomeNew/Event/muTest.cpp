#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "Event.h"


UNIT(EventTest)
    Event e1,e2("fire","6","1");

    e2.PrintEvent();
    e1.SetEvent("smoke");
    e1.PrintEvent();
    std::cout <<std::endl<< (e2 < e1 )<<std::endl;


END_UNIT

TEST_SUITE(event)
    TEST(EventTest)
END_SUITE
