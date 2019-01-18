/**
 * @file SmartHome.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "SmartHome.h"
#include "App.h"
#include "VContainer.h"



SmartHome::SmartHome(const std::string& _config)
{
    CreateFrom(_config);
}

void SmartHome::CreateFrom(const std::string& _config)
{
    std::vector<std::string> com;
    std::string COMMAND[] = {_config,"vector"};
    int size = 2;

    com.insert(com.begin(),COMMAND,COMMAND + size);


    App application(com);
    VContainer* Cpp = (VContainer*)application.Run();
    Cpp->PrintC();
}
