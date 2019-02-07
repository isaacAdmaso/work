#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "SoLoader.h"
#include "DeviceFactory.h"

UNIT(DyLib)
using namespace std;
typedef int(*func)(int* ,int*);

DeviceFactory<int,func> factory(new SoLoader<func>);

int r = factory.GetDevice("../../../O.S+temp/lib/libCulc.so","Add_F");
ASSERT_THAT(7 == r);

r = factory.GetDevice("../../../O.S+temp/lib/libCulc.so","Div_F");
ASSERT_THAT(0 == r);


r = factory.GetDevice("../../../O.S+temp/lib/libCulc.so","Sub_F");
ASSERT_THAT(-1 == r);



r = factory.GetDevice("../../../O.S+temp/lib/libCulc.so","Mult_F");
ASSERT_THAT(12 == r);


END_UNIT

TEST_SUITE(LOADER)
    TEST(DyLib)
END_SUITE
