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


class SmartHome:private Uncopy
{
public:
    SmartHome(const std::string& configPath);
    //for debug
    void Print();
private:
    std::vector<std::string> m_configVec;
};

#endif //__SMARTHOME_H__