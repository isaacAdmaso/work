/**
 * @file cTime.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "cTime.h"
using namespace std;



bool cTime_t::formart = false;


ostream&  operator << (ostream& _os,const cTime_t _w)
{
    _os <<_w.getTime();
    return _os;
}

