#include <iostream>
#include "mu_test.h"

#include "FileIn.h"
#include "ConsoleIn.h"
#include "Sfactory.h"

#include "Idest.h"
#include "FileOut.h"
#include "Console.h"



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

UNIT(consoleIn)
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

UNIT(baseIn)
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
    Isource* cP = factory.GetConsole();
    cout << "read from console(given by \"factory\") test"<<endl;
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


UNIT(fileOut)
using namespace std;
    FileOut fs("testFile");
    fs.PutString("in test");

END_UNIT


UNIT(screen)
using namespace std;
    Console fs(cout);
    fs.PutString("in test");

END_UNIT


TEST_SUITE(all)
	TEST(fileIn)
	TEST(consoleIn)
	TEST(baseIn)
	TEST(source_factory)
    TEST(fileOut)
    TEST(screen)
END_SUITE


//int main(int argc, char *argv[])
//{
//    extern char *optarg;
//	extern int optind;
//    int op = -1;
//    const char 
//
//    while ((op = getopt(argc,argv, IN_FLAGS)) != -1)
//    {
//		switch (op) 
//        {
//        case 'p':
//            pause = 1;
//			break;
//        case 'd':
//            delete = 1;
//			break;
//        case 'v':
//            verb = 1;
//			break;
//        case 'r':
//            resume = 1;
//            break;
//        case '?':
//            fprintf(stderr,FLAG_ERR_STR);
//			return 1;
//		}
//    }
//
//    return 0;
//}
//