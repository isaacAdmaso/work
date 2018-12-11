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
#include "predicate.h"

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

    int f = 7;
	int* ip = lArr.findItem(f);
    cout << *ip<<endl;

    f = 18;
    ip = vArr.findItem(f);
    cout << *ip<<endl;

    ip = vArr.eraseItem(i);
    cout << *ip<<endl;

    ip = lArr.eraseItem(i);
    cout << *ip<<endl;


    cout << vArr.firstItem()<<endl;
    cout << lArr.firstItem()<<endl;
    return 0;
}
