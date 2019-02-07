/**
 * @file IDynamicLoader.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __DYNLOADER_H__
#define __DYNLOADER_H__
#include <string>

template<class T>
class IDynamicLoader
{
public:
    virtual~IDynamicLoader();
    virtual T GetCTor(const std::string& _path,const std::string& _funcName) = 0;
};


#include "IDynamicLoader.hpp"

#endif //__DYNLOADER_H__