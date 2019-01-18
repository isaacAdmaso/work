#include <iostream>
#include "mu_test.h"

#include "FileOut.h"
#include "Console.h"
#include "Dfactory.h"
#include "Container.h"



UNIT(file)
using namespace std;
    FileOut fs("testFile");
    fs.PutString("in test");

END_UNIT


UNIT(screen)
using namespace std;
    Console fs(cout);
    fs.PutString("in test\n");

END_UNIT

UNIT(baseD)
using namespace std;
    Idest* fP = new FileOut("testFile");
    string test = "***********out test********\n";
    fP->PutString(test);
    delete fP;

    Idest* cP = new Console(cout);
    cP->PutString(test);
    delete cP;

END_UNIT

UNIT(dest_factory)
using namespace std;
    Dfactory factory;
    Idest* fP = factory.GetFile("testFile");
    string test = "***********out test********\n";
    fP->PutString(test);    
    delete fP;

    Idest* cP = factory.GetConsole();
    cP->PutString(test);
    delete cP;

    Idest* Cp = factory.GetContainer();
    Cp->PutString(test);
    Container* Cpp = dynamic_cast<Container*>(Cp); 
    if(Cpp != NULL){
        std::cout<<"in Container"<<endl;
        Cpp->PrintC();
    } 
    
END_UNIT


TEST_SUITE(destination)
    TEST(file)
    TEST(screen)
    TEST(baseD)
    TEST(dest_factory)
END_SUITE
