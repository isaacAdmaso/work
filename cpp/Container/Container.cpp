/**
 * @file Container.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include "Container.h"

using namespace std;

int main()
{
    Container_t<int, vector<int*> >  	vArr;    
    Container_t<int, list<int*> >  	lArr; 
    int i = 5,i1 = 6,i2 = 7,i3 = 8;

    vArr.insertNew(i);
    lArr.insertNew(i);
    vArr.insertNew(i1);
    lArr.insertNew(i1);
    vArr.insertNew(i2);
    lArr.insertNew(i2);
    vArr.insertNew(i3);
    lArr.insertNew(i3);

    cout << vArr.firstItem()<<endl;
    cout << lArr.firstItem()<<endl;
    cout << vArr.lastItem()<<endl;
    cout << lArr.lastItem()<<endl;
    


    return 0;
}
