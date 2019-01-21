/**
 * @file fruit.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "fruit.h"
#include "Visitor.h"

Fruit::Fruit(const std::string& _name, int _price,int weight)
:Item(_name,_price),m_weight(weight)
{
}


int Fruit::accept(IVisitor& _visit)
{
    return _visit.visit(*this);
}

int Fruit::GetPrice()
{
    return m_weight * m_price;
}
