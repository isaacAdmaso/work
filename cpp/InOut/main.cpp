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
    string mode1("a");
    string mode2("w");
    asciiIO_t  aIO(file1,mode1);
    asciiIO_t  bIO(file2,mode2);
    int 	 ri = 0,i = 5;
    float 	 rf = 0,f = 6.1;
    char  a = 'a',b = 'b';


    bIO << b << i  << f << a;			// Binary file
    bIO >> ri  >> rf  ; 
    aIO << a << i << f << b;  		// ASCII file ( with blanks )
    cout <<endl<< ri<<endl<<rf<<endl;
    return 0;
}
