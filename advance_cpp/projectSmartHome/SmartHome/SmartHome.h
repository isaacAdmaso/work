/**
 * @file SmartHome.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-19
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SMARTHOME_H__
#define __SMARTHOME_H__
#include <string>
#include <vector>
#include "uncopy.h"
#include "IAgent.h"
#include "IServer.h"


class SmartHome:private Uncopy
{
public:
    SmartHome(const std::string& configPath);
    ~SmartHome();
    void Run();
    void Print(std::vector<IAgent::AgentConfig>& _Agents);
private:
    bool BuildAgent(std::vector<std::string>& configVec,std::vector<IAgent::AgentConfig>& _Agents);
    void ParseLine(std::string& _line,std::string& _rtLine);
private:
    IServer* m_server;
};

#endif //__SMARTHOME_H__