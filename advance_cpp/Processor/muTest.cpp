#include <iostream>
#include <stdio.h>
#include "mu_test.h"

//sources
//#include "FileIn.h"
//#include "ConsoleIn.h"
#include "Sfactory.h"
#include "Isource.h"

//Destination
//#include "FileOut.h"
//#include "Console.h"
#include "Dfactory.h"
#include "Idest.h"

//Process
#include <vector>
#include <string>
#include "Cfactory.h"
#include "ITx.h"
//#include "Erase.h"
//#include "Container.h"
//#include "Lower.h"
//#include "Upper.h"
//#include "Shift.h"


#define FILE_IN     "./testFileIn"
#define FILE_OUT    "./testFile"
#define FILE_OUT2    "./testFile2"
#define FILE_OUT3    "./testFile3"
#define FILE_OUT4    "./testFile4"


//UNIT(fileIn)
//using namespace std;
//    FileIn fObj(FILE_IN);
//    //FileIn f2Obj(FileIn(fObj)); <- ask teacher  
//    string temp = fObj.GetString();
//    while(temp.length())
//    {
//        std::cout << temp <<std::endl;
//        temp = fObj.GetString();
//    }
//END_UNIT
//
//UNIT(consoleIn)
//using namespace std;
//    ConsoleIn cIn(cin);
//    cout << "read from console test"<<endl;
//    string temp = cIn.GetString();
//    while(temp != "break" )
//    {
//        std::cout << temp <<std::endl;
//        cout << "enter \"break\" to stop"<<endl;
//        temp = cIn.GetString();
//    }
//END_UNIT
//
//UNIT(baseIn)
//using namespace std;
//    Isource* fP = new FileIn(FILE_IN);
//    string tempF = fP->GetString();
//    while(tempF.length())
//    {
//        std::cout << tempF <<std::endl;
//        tempF = fP->GetString();
//    }
//    Isource* cP = new ConsoleIn(cin);
//    cout << "read from console (as base *) test"<<endl;
//    string tempC = cP->GetString();
//    while(tempC != "break" )
//    {
//        std::cout << tempC <<std::endl;
//        cout << "enter \"break\" to stop"<<endl;
//        tempC = cP->GetString();
//    }
//    delete fP;
//    delete cP;
//END_UNIT
//
//UNIT(source_factory)
//using namespace std;
//    Sfactory factory;
//    Isource* fP = factory.GetFile(FILE_IN);
//    string tempF = fP->GetString();
//    while(tempF.length())
//    {
//        std::cout << tempF <<std::endl;
//        tempF = fP->GetString();
//    }
//    Isource* cP = factory.GetConsole();
//    cout << "read from console(given by \"factory\") test"<<endl;
//    string tempC = cP->GetString();
//    while(tempC != "break" )
//    {
//        std::cout << tempC <<std::endl;
//        cout <<endl << "enter \"break\" to stop"<<endl;
//        tempC = cP->GetString();
//    }
//    delete fP;
//    delete cP;
//
//END_UNIT
//
//
//UNIT(fileOut)
//using namespace std;
//    FileOut fs(FILE_OUT);
//    fs.PutString("in test\n");
//
//END_UNIT
//
//
//UNIT(screen)
//using namespace std;
//    Console fs(cout);
//    fs.PutString("in test\n");
//
//END_UNIT
//
//
//UNIT(baseD)
//using namespace std;
//    Idest* fP = new FileOut(FILE_OUT2);
//    string test = "***********out test********\n";
//    fP->PutString(test);
//    delete fP;
//
//    Idest* cP = new Console(cout);
//    cP->PutString(test);
//    delete cP;
//
//END_UNIT
//
//UNIT(dest_factory)
//using namespace std;
//    Dfactory factory;
//    Idest* fP = factory.GetFile(FILE_OUT3);
//    string test = "***********out test********\n";
//    fP->PutString(test);    
//    delete fP;
//
//    Idest* cP = factory.GetConsole();
//    cP->PutString(test);
//    delete cP;
//    
//END_UNIT
//
//UNIT(plist)
//using namespace std;
//    string test = "YITSHAK";
//
//    ITx* eP = new Erase("AIEOU");
//    test = eP->Processor(test);
//    
//    ITx* lP = new Lower();
//    test = lP->Processor(test);
//    cout << test<<endl;
//    
//    ITx* uP = new Upper();
//    test = uP->Processor(test);
//    cout << test<<endl;
//    
//    std::vector<ITx*> pVec;
//    pVec.push_back(uP);
//    pVec.push_back(lP);
//    pVec.push_back(eP);
//    ITx* cP = new Container(pVec);
//    test = "abAcEdIAOBUCADEaIAAbEBOcUCdUD";
//    test = cP->Processor(test);
//    cout << test<<endl;
//
//END_UNIT
//
//UNIT(proc_factory)
//using namespace std;
//    
//    Cfactory cF;
//    string test = "YITSHAK";
//
//
//    ITx* eP = cF.GetErase("AIEOU");
//    test = eP->Processor(test);
//    
//    ITx* lP = cF.GetLower();
//    test = lP->Processor(test);
//    cout << test<<endl;
//    
//    ITx* uP = cF.GetUpper();
//    test = uP->Processor(test);
//    cout << test<<endl;
//    
//    std::vector<ITx*> pVec;
//    pVec.push_back(uP);
//    pVec.push_back(lP);
//    pVec.push_back(eP);
//    ITx* cP = cF.GetContainer(pVec);
//    test = "abAcEdIAOBUCADEaIAAbEBOcUCdUD";
//    test = cP->Processor(test);
//    cout << test<<endl;
//
//END_UNIT
//
UNIT(app)
using namespace std;
    Sfactory sourceF;
    Dfactory destF;
    Cfactory procF;

    Isource* fIn = sourceF.GetFile(FILE_IN);
    Isource* cIn = sourceF.GetConsole();
    Idest*  fOut = destF.GetFile(FILE_OUT4);
    Idest*  cOut = destF.GetConsole();
    ITx*    eProc =  procF.GetErase("aeiuo");
    ITx*    lProc =  procF.GetLower();
    ITx*    uProc =  procF.GetUpper();
    ITx*    sProc =  procF.GetShift(1);
    std::vector<ITx*> pVec;
    pVec.push_back(lProc);
    pVec.push_back(eProc);
    pVec.push_back(uProc);
    pVec.push_back(sProc);
    ITx*    cProc =  procF.GetContainer(pVec);


    string temp = fIn->GetString();
    while(temp.length())
    {
        temp = cProc->Processor(temp);
        fOut->PutString(temp);
        cOut->PutString(temp);
        temp = fIn->GetString();
    }
    delete fIn;

    cout << endl;
    cout << "read from console(given by \"factory\") test"<<endl;
    temp = cIn->GetString();
    while(temp != "break")
    {
        temp = cProc->Processor(temp);
        fOut->PutString(temp);
        cOut->PutString(temp);
        cout << endl;
        cout << "enter \"break\" to stop"<<endl;
        temp = cIn->GetString();
    }
    delete cIn;
END_UNIT

TEST_SUITE(all)
	//TEST(fileIn)
	//TEST(consoleIn)
	//TEST(baseIn)
	//TEST(source_factory)
    //TEST(fileOut)
    //TEST(screen)
    //TEST(baseD)
    //TEST(dest_factory)
    //TEST(plist)
    //TEST(proc_factory)
    TEST(app)
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