/**
 * @file Container.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-18
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <string>
#include <vector>
#include "uncopy.h"
#include "Idest.h"


class Container: public Idest,private Uncopy
{
public:
    std::vector<std::string> my_Container;
    virtual void PutString(const std::string& _str);
    void PrintC();
};

#endif //__CONTAINER_H__