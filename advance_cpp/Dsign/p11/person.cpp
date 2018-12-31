/**
 * @file person.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "person.h"

person::person(Irole* role)
:_role(role)
{
}

void person::Goal()
{
    _role->Goal();
}