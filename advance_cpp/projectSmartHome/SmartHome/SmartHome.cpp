/**
 * @file SmartHome.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>      // std::stringstream
#include "SmartHome.h"
#include "Reader.h"
#include "IAgent.h"
#include "AgentHandler.h"

SmartHome::SmartHome(const std::string& configPath)
{
    std::vector<std::string> configVec; 
    Reader sh1(configPath,configVec);
    BuildAgent(configVec);
    Print();
    AgentHandler Ah(m_Agents);
    std::cout<<std::endl<<std::endl<<"print agent Handler"<<std::endl;
    Ah.Print();
    std::cout<<std::endl<<std::endl<<"agent Handler Run"<<std::endl;
    Ah.Run();
}


SmartHome::~SmartHome()
{
}

void SmartHome::Print()
{
    int line = 0;
    for (std::vector<IAgent::AgentConfig>::const_iterator i = m_Agents.begin();\
    i != m_Agents.end(); ++i)
    {
        std::cout<<std::endl <<"************agent: "<< line++<<"*************" <<std::endl;
        std::cout << *i ;
    }
    std::cout<<std::endl;
}

void SmartHome::ParseLine(std::string& _line,std::string& _rtLine)
{
    std::stringstream tokenInLIne(_line);
    std::getline(tokenInLIne, _rtLine,'=') ;
    std::getline(tokenInLIne, _rtLine);

}

bool SmartHome::BuildAgent(std::vector<std::string>& configVec)
{
    IAgent::AgentConfig agentData;

   for (std::vector<std::string>::const_iterator i = configVec.begin();\
    i != configVec.end(); ++i)
    {
        std::stringstream token(*i);
        std::string line;

        std::getline(token, line,'\n') ;
        agentData.m_id = line;

        std::getline(token, line,'\n') ;
        std::string inLine;
        ParseLine(line,inLine);
        agentData.m_type = inLine;

        std::getline(token, line,'\n') ;
        ParseLine(line,inLine);
        agentData.m_room = inLine;

        std::getline(token, line,'\n') ;
        ParseLine(line,inLine);
        agentData.m_floor = inLine;

        std::getline(token, line,'\n') ;
        ParseLine(line,inLine);
        agentData.m_log = inLine;

        std::getline(token, line,'\n') ;
        ParseLine(line,inLine);
        agentData.m_configData = inLine;

        m_Agents.push_back(agentData);   
    } 
    return true;
}

