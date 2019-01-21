/**
 * @file Fruit.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __FRUIT_H__
#define __FRUIT_H__

#include "Item.h"


class Fruit:public Item
{
public:
    Fruit(const std::string& _name, int _price,int weight);
    virtual int GetPrice();
    virtual int accept(IVisitor& _visit);
private:
    int m_weight;
};

#endif //__FRUIT_H__
