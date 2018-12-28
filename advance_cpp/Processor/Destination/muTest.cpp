#include <iostream>
#include "mu_test.h"
#include "Idest.h"
#include "FileOut.h"



UNIT(file)
using namespace std;
    FileOut fs("testFile");
    fs.PutString("in test");

END_UNIT


TEST_SUITE(destination)
    TEST(file)

END_SUITE
