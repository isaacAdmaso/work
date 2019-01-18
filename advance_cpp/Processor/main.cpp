/**
 * @brief 
 * 
 */
#include "App.h"
#define MIN 64

using namespace std;
int main(int argc, char *argv[]){

    std::vector<std::string> com;
    char COMMAND[][MIN] = {"../projectSmartHome/Configuration/smtestconf.txt","c"};

    if(argc < MIN)
        com.insert(com.begin(),COMMAND,COMMAND + (sizeof(COMMAND)/sizeof(COMMAND[0])));
    else 
        com.insert(com.begin(),argv + 1,argv + argc);


    App application(com);
    application.Run();
    return 0;
}
//        char COMMAND[][MIN] = {"-f","c","-d","c","-p","e","k","l","u","s","1"}