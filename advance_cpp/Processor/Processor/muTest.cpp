#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include "mu_test.h"
#include "ITx.h"
#include "Erase.h"
#include "Container.h"
#include "Lower.h"
#include "Upper.h"
#include "Cfactory.h"

UNIT(plist)
using namespace std;
    string test = "YITSHAK";

    ITx* eP = new Erase("AIEOU");
    test = eP->Processor(test);
    
    ITx* lP = new Lower();
    test = lP->Processor(test);
    cout << test<<endl;
    
    ITx* uP = new Upper();
    test = uP->Processor(test);
    cout << test<<endl;
    
    std::vector<ITx*> pVec;
    pVec.push_back(uP);
    pVec.push_back(lP);
    pVec.push_back(eP);
    ITx* cP = new Container(pVec);
    test = "abAcEdIAOBUCADEaIAAbEBOcUCdUD";
    test = cP->Processor(test);
    cout << test<<endl;

END_UNIT

UNIT(factory)
using namespace std;
    
    Cfactory cF;
    string test = "YITSHAK";


    ITx* eP = cF.GetErase("aeiouAIEOU");
    test = eP->Processor(test);
    
    ITx* lP = cF.GetLower();
    test = lP->Processor(test);
    cout << test<<endl;
    
    ITx* uP = cF.GetUpper();
    test = uP->Processor(test);
    cout << test<<endl;
    
    std::vector<ITx*> pVec;
    pVec.push_back(uP);
    pVec.push_back(lP);
    pVec.push_back(eP);
    ITx* cP = cF.GetContainer(pVec);
    test = "abAcEdIAOBUCADEaIAAbEBOcUCdUDZ";
    test = cP->Processor(test);
    cout << test<<endl;

    ITx* sP = cF.GetShift(1);
    test = sP->Processor(test);
    cout << test<<endl;


END_UNIT

TEST_SUITE(processor)
    TEST(plist)
    TEST(factory)
    
END_SUITE
