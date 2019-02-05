/**
 * @file SoLoader.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-02-05
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __SOLOADER_H__
#define __SOLOADER_H__
#include "IDynamicLoader.h"


template<class T>
class SoLoader:public IDynamicLoader<T>
{
public:
    //SoLoader(){}
    //~SoLoader(){}
    T GetCTor(const std::string& _path,const std::string& _funcName);
};

#include "SoLoader.hpp"

#endif //__SOLOADER_H__