#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "IDynamicLoader.h"
#include "SoLoader.h"

UNIT(DyLib)
using namespace std;
typedef int(*func)(int* ,int*);


IDynamicLoader<func>* loader = new  SoLoader<func>;

END_UNIT

TEST_SUITE(LOADER)
    TEST(DyLib)
END_SUITE
