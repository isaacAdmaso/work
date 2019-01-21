/**
 * @file Visitor.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __VISITOR_H__
#define __VISITOR_H__
#include "fruit.h"
#include "Books.h"


class IVisitor
{
public:
    virtual int visit(Books& _b) = 0;
    virtual int visit(Fruit& _f) = 0;
};


#endif //__VISITOR_H__