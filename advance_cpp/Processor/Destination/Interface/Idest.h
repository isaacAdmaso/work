/**
 * @file Idest.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __IDEST_H__
#define __IDEST_H__
#include <string>


class Idest
{
public:
    virtual ~Idest() = 0;
    virtual void PutString(const std::string& _str) = 0;
};




#endif //__IDEST_H__