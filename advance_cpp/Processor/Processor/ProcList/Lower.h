/**
 * @file Lower.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __LOWER_H__
#define __LOWER_H__
#include "ITx.h"
#include <string>

class Lower: public ITx
{
public:
    typedef std::string::iterator iter_t;

    virtual std::string Processor(const std::string& _str);
};

#endif //__LOWER_H__