#include <iostream>
#include "mu_test.h"

#include "FileIn.h"
#include "ConsoleIn.h"
#include "Sfactory.h"


UNIT(fileIn)
using namespace std;
    FileIn fObj("./testFileIn");
    //FileIn f2Obj(FileIn(fObj)); <- ask teacher  
    string temp = fObj.GetString();
    while(temp.length())
    {
        std::cout << temp <<std::endl;
        temp = fObj.GetString();
    }
END_UNIT

UNIT(console)
using namespace std;
    ConsoleIn cIn(cin);
    cout << "read from console test"<<endl;
    string temp = cIn.GetString();
    while(temp != "break" )
    {
        std::cout << temp <<std::endl;
        cout << "enter \"break\" to stop"<<endl;
        temp = cIn.GetString();
    }
END_UNIT

UNIT(base)
using namespace std;
    Isource* fP = new FileIn("./testFileIn");
    string tempF = fP->GetString();
    while(tempF.length())
    {
        std::cout << tempF <<std::endl;
        tempF = fP->GetString();
    }
    Isource* cP = new ConsoleIn(cin);
    cout << "read from console (as base *) test"<<endl;
    string tempC = cP->GetString();
    while(tempC != "break" )
    {
        std::cout << tempC <<std::endl;
        cout << "enter \"break\" to stop"<<endl;
        tempC = cP->GetString();
    }
    delete fP;
    delete cP;
END_UNIT

UNIT(source_factory)
using namespace std;
    Sfactory factory;
    Isource* fP = factory.GetFile("./testFileIn");
    string tempF = fP->GetString();
    while(tempF.length())
    {
        std::cout << tempF <<std::endl;
        tempF = fP->GetString();
    }
    delete fP;
    
    Isource* cP = factory.GetConsole();
    cout << "read from console(given by \"factory\") test"<<endl;
    string tempC = cP->GetString();
    while(tempC != "break" )
    {
        std::cout << tempC <<std::endl;
        cout << "enter \"break\" to stop"<<endl;
        tempC = cP->GetString();
    }
    delete cP;

END_UNIT


TEST_SUITE(Source)
	TEST(fileIn)
	TEST(console)
	TEST(base)
	TEST(source_factory)


END_SUITE
