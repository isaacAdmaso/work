/**
 * @file SmartHome.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-08
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SMARTHOME_H__
#define __SMARTHOME_H__
#include <string>


class SmartHome
{
public:
    SmartHome(const std::string& _config);
    ~SmartHome(){}
    bool Init(std::string);

private:
    void CreateFrom(const std::string& _config);
};





#endif //__SMARTHOME_H__