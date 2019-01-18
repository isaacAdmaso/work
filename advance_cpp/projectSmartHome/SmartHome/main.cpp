/**
 * @brief 
 * 
 */

#include "SmartHome.h"

 
int main(int argc, char *argv[]){

    std::string configPath = "../Configuration/smtestconf.txt";
    SmartHome sh1(configPath);

    return 0;
}