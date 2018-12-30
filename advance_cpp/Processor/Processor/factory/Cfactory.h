/**
 * @file Cfactory.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CFACTORY_H__
#define __CFACTORY_H__
#include <vector>
#include "ITx.h"

class Cfactory 
{
private:
public:

ITx*      GetContainer(std::vector<ITx*>& _pVec);
ITx*      GetErase(const std::string strDel);
ITx*      GetLower();
ITx*      GetUpper();
ITx*      GetShift(const int _shift);
};


#endif //__CFACTORY_H__