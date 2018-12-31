#include <iostream>
#include <stdio.h>
#include <unistd.h>

//sources
#include "Sfactory.h"
#include "Isource.h"

//Destination
#include "Dfactory.h"
#include "Idest.h"

//Process
#include <vector>
#include <string>
#include "Cfactory.h"
#include "ITx.h"



#define FILE_IN     "./testFileIn"
#define FILE_OUT    "./MainTestFile"
#define IN_FLAGS    "s:f:d:f:p:c:"


const char USAGE[]="Usage:  [-s F or C] [-f name]                       \
                            [-d F or C] [-f name]                       \
                            [-p Erase Shift Lower Upper Container ]     \
                            [-c Erase Shift Lower Upper ]\n";


int main(int argc, char *argv[]){
using namespace std;

    string temp;
    for(int i = 1; i < argc; ++i )
    {
        temp += argv[i];
        temp += " ";   
    }

    Sfactory sourceF;
    Dfactory destF;
    Cfactory procF;
    Isource* fIn = sourceF.GetFile(FILE_IN);
    Isource* cIn = sourceF.GetConsole();
    Idest*  fOut = destF.GetFile(FILE_OUT);
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
}

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