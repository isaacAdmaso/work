/**
 * @brief 
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include "Reader.h"


void PrintC(std::vector<std::string>& configVec)
{
    int line = 0;
    for (std::vector<std::string>::const_iterator i = configVec.begin();\
    i != configVec.end(); ++i)
    {
        std::cout<<std::endl <<"************agent: "<< line++<<"*************" <<std::endl;
        std::cout << *i << ' ';
    }
    std::cout<<std::endl;
}


int main(int argc, char *argv[]){
    std::vector<std::string> configVec;

    std::string configPath = "../Configuration/smtestconf.input";
    Reader sh1(configPath,configVec);
    PrintC(configVec);
    return 0;
}