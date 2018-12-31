/**
 * @file Student.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-31
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __STUDENT_H__
#define __STUDENT_H__
#include "ITrole.h"

class Student:public ITrole
{
public:
    ~Student();
    void Gole();
};



#endif //__STUDENT_H__