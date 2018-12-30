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
#include "ITx.h"
#include "Container.h"
#include "Erase.h"
#include "Lower.h"
#include "Upper.h"
#include "Shift.h"

class Cfactory 
{
private:
public:

Container*  GetContainer(std::vector<ITx*>& _pVec);
Erase*      GetErase(const std::string strDel);
Lower*      GetLower();
Upper*      GetUpper();
Shift*      GetShift(const int _shift);
};


#endif //__CFACTORY_H__