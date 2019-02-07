#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "IDynamicLoader.h"
#include "SoLoader.h"

UNIT(DyLib)
using namespace std;
typedef int(*func)(int* ,int*);

IDynamicLoader<func>* loader = new  SoLoader<func>;

func f =  loader->GetCTor("../../../O.S+temp/lib/libCulc.so","Add_F");
int k = 3,j = 4;
int r = f(&k,&j);
ASSERT_THAT(7 == r);

f =  loader->GetCTor("../../../O.S+temp/lib/libCulc.so","Div_F");
k = 3,j = 4;
r = f(&k,&j);
ASSERT_THAT(0 == r);


f =  loader->GetCTor("../../../O.S+temp/lib/libCulc.so","Sub_F");
k = 3,j = 4;
r = f(&k,&j);
ASSERT_THAT(-1 == r);



f =  loader->GetCTor("../../../O.S+temp/lib/libCulc.so","Mult_F");
k = 3,j = 4;
r = f(&k,&j);
ASSERT_THAT(12 == r);

delete loader;

k = 3,j = 10;
r = f(&k,&j);
ASSERT_THAT(30 == r);

END_UNIT

TEST_SUITE(LOADER)
    TEST(DyLib)
END_SUITE
