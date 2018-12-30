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


Container*  Cfactory::GetContainer(std::vector<ITx*>& _pVec)
{
    return new Container(_pVec);
}

Erase*      Cfactory::GetErase(const std::string strDel)
{
    return new Erase(strDel);
}

Lower*      Cfactory::GetLower()
{
    return new Lower();
}

Upper*      Cfactory::GetUpper()
{
    return new Upper();
}

Shift*      Cfactory::GetShift(const int _shift)
{
    return new Shift(_shift);
}