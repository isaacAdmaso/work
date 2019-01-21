/**
 * @file Books.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Visitor.h"
#include "Books.h"

Books::Books(const std::string& _name, int _price)
:Item(_name,_price)
{
}

int Books::accept(IVisitor& _visit)
{
    return _visit.visit(*this);
}

int Books::GetPrice()
{
    return m_price;
}