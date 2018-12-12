/**
 * @file main.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include "virIO.h"
#include "asciiIO.h"
#include "binIO.h"

int main()
{
    string file1("./file1");
    string file2("./file2");
    string mode1("w+");
    string mode2("wb+");
    asciiIO_t  aIO(file1,mode1);
    binIO_t  bIO(file2,mode2);
    int 	 ri = 0,i = 5;
    float 	 rf = 0,f = 6.1;
    short  a = 3,b = 7;
    char name[16] = "yitshak";
//    char  a = 'a',b = 'b';


    bIO << b << ' ' << i << ' ' << f << ' ' << a;	
    bIO.setPos(0);		
    cout <<aIO.getStatus()<<" "<<bIO.getStatus()<<endl;
    bIO >> ri  >> rf  ; 
    cout << ri<<" "<<rf<<endl;
    aIO<< b << ' ' << i << ' ' << f << ' ' << a;  		
    aIO.setPos(0);		
    aIO >> ri  >> rf  ; 
    cout << ri<<" "<<rf<<endl;
    cout <<aIO.getStatus()<<" "<<bIO.getStatus()<<endl;

    bIO << name,16;
    bIO >> name,16;



    return 0;
}
