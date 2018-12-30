/**
 * @file Cfactory.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Cfactory.h"
#include "Container.h"
#include "Erase.h"
#include "Lower.h"
#include "Upper.h"
#include "Shift.h"


ITx*  Cfactory::GetContainer(std::vector<ITx*>& _pVec)
{
    return new Container(_pVec);
}

ITx*      Cfactory::GetErase(const std::string strDel)
{
    return new Erase(strDel);
}

ITx*      Cfactory::GetLower()
{
    return new Lower();
}

ITx*      Cfactory::GetUpper()
{
    return new Upper();
}

ITx*      Cfactory::GetShift(const int _shift)
{
    return new Shift(_shift);
}