/**
 * @file Reader.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Reader.h"
#include "App.h"
#include "VContainer.h"



Reader::Reader(const std::string& _config,std::vector<std::string>& _configVec)
{
    CreateFrom(_config,_configVec);
}

void Reader::CreateFrom(const std::string& _config,std::vector<std::string>& _configVec)
{
    std::vector<std::string> com;
    std::string COMMAND[] = {_config,"vector"};
    int size = 2;

    com.insert(com.begin(),COMMAND,COMMAND + size);


    App application(com);
    VContainer* Cpp = (VContainer*)application.Run();
    for (unsigned int i = 0; i < (Cpp->my_Container).size(); i++) 
        _configVec.push_back((Cpp->my_Container)[i]); 
}
