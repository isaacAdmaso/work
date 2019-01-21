/**
 * @file Item.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __ITEM_H__
#define __ITEM_H__
#include <string>

class IVisitor;


class Item
{
public:
    virtual ~Item();
    Item(const std::string& _name, int _price);
    virtual int accept(IVisitor& _visit) = 0;
    virtual int GetPrice() = 0;
protected:
    std::string m_name;
    int m_price;    
};

#endif //__ITEM_H__
