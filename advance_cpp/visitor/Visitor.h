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


class Visitor
{
public:
    void visit(Books& _b);
    void visit(Fruit& _f);
};


#endif //__VISITOR_H__