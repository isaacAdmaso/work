#include <iostream>
#include "FileIn.h"
#include "ConsleIn.h"
#include "mu_test.h"


UNIT(fileIn)
using namespace std;
    FileIn fObj("./FileIn.h");
    //FileIn f2Obj(FileIn(fObj));
    string temp = fObj.GetString();
    while(temp.length())
    {
        std::cout << temp <<std::endl;
        temp = fObj.GetString();
    }
END_UNIT

UNIT(console)
using namespace std;
    ConsleIn cIn(cin);
    string temp = cIn.GetString();
    while(temp != "break" )
    {
        std::cout << temp <<std::endl;
        temp = cIn.GetString();
    }
END_UNIT

UNIT(base)
END_UNIT

TEST_SUITE(Source)
	TEST(fileIn)
	TEST(console)
	TEST(base)


END_SUITE
