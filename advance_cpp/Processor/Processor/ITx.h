/**
 * @file ITx.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __ITX_H__
#define __ITX_H__
#include <string>


class ITx
{
private:

public:
    virtual ~ITx() = 0;
    virtual std::string Processor(const std::string& _str) const  = 0;
};



#endif //__ITX_H__