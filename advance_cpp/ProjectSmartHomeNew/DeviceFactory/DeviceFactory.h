/**
 * @file DeviceFactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-07
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __DEVICEFACTORY_H__
#define __DEVICEFACTORY_H__
#include <string>

#include "IDynamicLoader.h"


template<class T,class U>
class DeviceFactory
{
public:
    DeviceFactory(IDynamicLoader<U>* _loader);
    T GetDevice(const std::string& _path,const std::string& _funcName);
    ~DeviceFactory();

private:
    IDynamicLoader<U>* m_Loader;
};


#include "DeviceFactory.hpp"

#endif //__DEVICEFACTORY_H__
