/**
 * @file Isource.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __ISOURCE_H__
#define __ISOURCE_H__
#include <string>


class Isource
{
private:
public:
    virtual ~Isource() = 0;
    virtual std::string GetString() = 0;
};



#endif //__ISOURCE_H__