#include <iostream>
#include "mu_test.h"
#include "Idest.h"
#include "FileOut.h"
#include "Console.h"



UNIT(file)
using namespace std;
    FileOut fs("testFile");
    fs.PutString("in test");

END_UNIT


UNIT(screen)
using namespace std;
    Console fs(cout);
    fs.PutString("in test");

END_UNIT

TEST_SUITE(destination)
    TEST(file)
    TEST(screen)

END_SUITE
