/**
 * @file cDateTime.cpp
 * @version 0.1
 * @date 2018-12-03
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#include <iostream>
#include "cDateTime.h"
using namespace std;

int main()
{
    int i;
    bool n = false;
    cDateTime_t test1;
    //cTime_t test
    cDateTime_t test2(test1);

    for(i = 0;i < 3;++i)
    {
        test1.setFormatD(i);
        test1.setFormatT(n);
        cout << "format: "<<i<<endl;
        cout << test1<<endl;
        cout << test2<<endl;
        cout << test1.getTime()<<endl;
        cout << test2.getTime()<<endl;
        test1.setTime();
        cout << test1.getTime()<<endl;
        test2.getHours();
        test2.getMinutes();
        test2.getSeconds();
        cout << test2.getTime()<<endl;
        cout << (cTime_t)test2 + test1<<endl;
        cout << ((cTime_t)test1 += test1)<<endl;
        //cTime_t test
        cDate_t test3;
        cDate_t test4(test3);
        cout << test3<<endl;
        cout << test4<<endl;
        cout << test3.getDate()<<endl;
        cout << test4.getDate()<<endl;
        test3.setDate();
        cout << test3.getDate()<<endl;
        test4.getyear();
        test4.getMon();
        test4.getDay();
        cout << test4.getDate()<<endl;
        cout << (cDate_t)test4 + test3<<endl;
        cout << test3<<endl;
        n = !n;
        cout << "change format"<<endl;

    }
    

    return 0;
}


