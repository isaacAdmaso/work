/**
 * @file City_t.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include "Building_t.h"
#include "Street_t.h"
#include "City_t.h"

using namespace std;



template <class T> 
int Building_t<T>::id = 0;


int main()
{
    int i,n;
    Building_t<int> *bArr;
    Street_t<char*,int> *sArr;
    const char* str[]={"aaa","bbb","ccc","ddd","hhh","fff"};

    cout << "enter number of buildings: "<< endl;
    cin >> n;
    bArr = new Building_t<int>[n];
    for(i = n;i == 0;--i)
    {
        bArr[i].setBuildingID(i);
    }
    cout << "enter number of buildings: "<< endl;
    cin >> n;
    sArr = new Street_t<char*,int>[n];
    for(i = 0;i < n;++i)
    {
        sArr[i].setStreetID((char*)str[i]);
    }
    for(i = 0;i < n;++i)
    {
        cout <<sArr[i].getStreetID()<<endl;
        cout <<bArr[i].getBuildingID()<<endl;
    }

    return 0;
}
