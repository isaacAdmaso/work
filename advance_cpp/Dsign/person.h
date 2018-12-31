/**
 * @file person.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __PERSON_H
#define __PERSON_H
#include <string>
#include "Irole.h"

class person
{
private:
    Irole* _role;

public:
    person(Irole* role);
    void Goal();
};



#endif //__PERSON_H