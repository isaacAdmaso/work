/**
 * @brief 
 * 
 */
#include <vector>
#include <string>
#include "SmartHome.h"


int main(int argc, char *argv[]){

    std::string configPath = "../Configuration/smtestconf.input";
    SmartHome sh1(configPath);
    sh1.Run();
    return 0;
}