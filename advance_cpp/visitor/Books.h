/**
 * @file Books.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __BOOKS_H__
#define __BOOKS_H__

#include "Item.h"


class Books:public Item
{
public:
    Books(const std::string& _name, int _price);
    virtual int accept(IVisitor& _visit);
    virtual int GetPrice();
};

#endif //__BOOKS_H__
