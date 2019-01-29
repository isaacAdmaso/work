/**
 * @file Runable.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-29
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __RUNABLE_H__
#define __RUNABLE_H__

class Runable
{
public:
    virtual ~Runable(){}
    virtual void** Run() = 0;
};


#endif //__RUNABLE_H__