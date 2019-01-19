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


class SmartHome:private Uncopy
{
public:
    SmartHome(const std::string& configPath);
    bool BuildAgent(std::vector<std::string>& configVec);
    //for debug
    void Print();
private:
    std::vector<IAgent::AgentConfig> m_Agents;
    void ParseLine(std::string& _line,std::string& _rtLine);
};

#endif //__SMARTHOME_H__