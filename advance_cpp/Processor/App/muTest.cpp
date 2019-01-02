#include "mu_test.h"
#include "App.h"
#include <stdio.h>
#include <vector>

char COMMAND[][6] = {"c","c","e","k","l","u","s","1"};

UNIT(app)
using namespace std;
    std::vector<std::string> com;
    com.insert(com.begin(),COMMAND,COMMAND + (sizeof(COMMAND)/sizeof(COMMAND[0])));
    App application(com);
    application.Run();
END_UNIT


TEST_SUITE(Application)
    TEST(app)
END_SUITE

