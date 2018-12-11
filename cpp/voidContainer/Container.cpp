/**
 * @file Container.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stdexcept>
#include <iostream>
#include "Container.h"
#include "predicate.h"

using namespace std;

int main()
{
    Container_t<int, vector>  	vArr;    
    Container_t<int, list>  	lArr; 
    int i ;
    int iArr[] = {1,2,3,4,5,6,7,8,9,0,1,2,18,3,4,6,7,8,9};

    for(i = 0;i < 18;++i)
    {
        vArr.insertNew(iArr[i]);
        lArr.insertNew(iArr[i]);

    }
    

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
