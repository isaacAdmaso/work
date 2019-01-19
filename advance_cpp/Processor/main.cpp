/**
 * @brief 
 * 
 */
#include "VContainer.h"
#include "App.h"
#define MIN 64

using namespace std;
int main(int argc, char *argv[]){

    VContainer* Cpp;
    std::vector<std::string> com;
    char COMMAND[][MIN] = {"../projectSmartHome/Configuration/smtestconf.input","vector"};

    if(argc < MIN)
        com.insert(com.begin(),COMMAND,COMMAND + (sizeof(COMMAND)/sizeof(COMMAND[0])));
    else 
        com.insert(com.begin(),argv + 1,argv + argc);


    App application(com);

    Cpp = (VContainer*)application.Run();
    Cpp->PrintC();
    return 0;
}
//        char COMMAND[][MIN] = {"-f","c","-d","c","-p","e","k","l","u","s","1"}