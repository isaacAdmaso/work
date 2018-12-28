#include <iostream>
#include <stdio.h>
#include <string>
#include "mu_test.h"
#include "ITx.h"


UNIT(plist)
using namespace std;
    string test = "test";
    cout << test<<endl;

END_UNIT


TEST_SUITE(processor)
    TEST(plist)
    
END_SUITE
