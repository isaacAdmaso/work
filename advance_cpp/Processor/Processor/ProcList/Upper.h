/**
 * @file Upper.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __UPPER_H__
#define __UPPER_H__
#include "ITx.h"
#include <string>

class Upper: public ITx
{
public:
    typedef std::string::iterator iter_t;

    virtual std::string Processor(const std::string& _str);
};

#endif //__UPPER_H__