/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include <list>
#include "Visitor.h"
#include "Item.h"
#include "Books.h"
#include "fruit.h"



/**hollydays: 5% off on all items */
class v1:public IVisitor
{
public:
    int  visit(Books& _b)
    {
        return (_b.GetPrice())*0.95;
    }
    int  visit(Fruit& _f)
    {
        return (_f.GetPrice())*0.95;
    }

};

/**book week: all books 50% off */
class v2:public IVisitor
{
public:
    int  visit(Books& _b)
    {
        return (_b.GetPrice())/2;
    }
    int  visit(Fruit& _f)
    {
        return _f.GetPrice();
    }
};


#define Fruit1  "fruit1"
#define PriceF1     1 
#define WeightF1    1
#define Fruit2  "fruit2"
#define PriceF2     2
#define WeightF2     2  
#define Fruit3 "fruit3"
#define PriceF3     3
#define WeightF3    3

#define Book1 "book1"
#define PriceB1     5
#define Book2 "book2"
#define PriceB2     10
#define Book3 "book3"
#define PriceB3     15


int main()
{
    std::list<Item*> shoppingCart;
    
    Fruit f1(Fruit1,PriceF1,WeightF1);
    Fruit f2(Fruit2,PriceF2,WeightF2);
    Fruit f3(Fruit3,PriceF3,WeightF3);

    Books b1(Book1,PriceB1); 
    Books b2(Book2,PriceB2);
    Books b3(Book3,PriceB3); 

    shoppingCart.push_back(&f1);
    shoppingCart.push_back(&f2);
    shoppingCart.push_back(&f3);
    shoppingCart.push_back(&b1);
    shoppingCart.push_back(&b2);
    shoppingCart.push_back(&b3);

    int total_price1 = 0;/**hollyday */
    int total_price2 = 0;/**book week */
    int real_price = 0;

    v1 hollyday_Price;
    v2 bookWeek_price;

    for(std::list<Item*>::iterator it = shoppingCart.begin();it != shoppingCart.end();it++)
    {
        real_price += (*it)->GetPrice(); 

        total_price1 += (*it)->accept(hollyday_Price); 
        
        total_price2 += (*it)->accept(bookWeek_price); 
    }

    std::cout<<std::endl<<"raw price: "<<real_price<<std::endl;
    std::cout<<std::endl<<"hollydays price: "<<total_price1<<std::endl;
    std::cout<<std::endl<<"book week price: "<<total_price2<<std::endl;

    return 0;
}