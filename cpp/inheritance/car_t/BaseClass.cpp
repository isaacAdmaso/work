/**
 * @file BaseClass.cpp
 * @brief for car and bus
 * @version 0.1
 * @date 2018-12-02
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "BaseClass.h"


int  BaseClass::defCapacity = 0; 
int  BaseClass::nCars = 0;
bool BaseClass::isAuto = false;

/*
istream& operator >> (istream& _os,BaseClass _s)
{
    char tempStr[MAX];

    _os >> tempStr;
    _s.setString(tempStr);
    return _os;
}
*/
ostream&  operator << (ostream& _os,const BaseClass _s)
{
    _os << "name:"  <<_s.getName()<<endl;
    return _os;
}

