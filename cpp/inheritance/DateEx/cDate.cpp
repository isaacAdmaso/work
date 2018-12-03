/**
 * @file cDate.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "cDate.h"


int cDate_t::formart = 0;


ostream&  operator << (ostream& _os,const cDate_t _d)
{
    _os <<_d.getDate();
    return _os;
}


