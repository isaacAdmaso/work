/**
 * @file main.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <string.h>
#include <iostream>
#include "virIO.h"
#include "asciiIO.h"
#include "binIO.h"

int main()
{
    string file2("./file2");
    string mode2("wb");
    string rmode2("rb");
    binIO_t  bIO(file2,mode2);
    int  	    ri = 0,i = 5;
    float       rf = 0,f = 6.1;
    short       ra,rb,a = 3,b = 7;
    char        rach,rbch,ach = 'a',bch = 'b';

    char name[16] = "yitshak";
    int  len      = strlen(name);

    bIO << name,len;
    bIO << f << i << a << b << ach << bch;
    bIO.~binIO_t();
    name[0] = '\0';

    binIO_t  rtbIO(file2,rmode2);
    rtbIO >> name,len;
    rtbIO >> rf >> ri >> ra >> rb >> rach >> rbch;
    cout << name << endl << rbch<< endl << ra<< endl << ri<< endl << rb<< endl << rach<< endl << rf<< endl<< endl;


    i = 1;f = 3.6;a = 9;b = 11;ach = 'c';bch = 'd';
    string file1("./file1");
    string mode1("w");
    string rmode1("r");
    asciiIO_t  aIO(file1,mode1);
    aIO << f << ' ' << i << ' ' << a << ' ' << b << ' ' << ach << ' ' ;
    aIO<< bch;
    aIO.~asciiIO_t();
    asciiIO_t  rtaIO(file1,rmode1);
    rtaIO >> rf >> ri >> ra >> rb;
    rtaIO >> rach;
    rtaIO >> rbch;
    cout << rf<< endl << ri<< endl << ra<< endl << rb<< endl << rach<< endl << rbch<< endl;












    return 0;
}
    //write
    //bIO << b << i << f  << a;	
    //bIO.setPos(0);		
    //cout <<aIO.getStatus()<<" "<<bIO.getStatus()<<endl;
    //bIO >> ri  >> rf  ; 
    //cout << ri<<" "<<rf<<endl;
    //aIO<< b << ' ' << i << ' ' << f << ' ' << a;  		
    //aIO.setPos(0);		
    //aIO >> ri  >> rf  ; 
    //cout << ri<<" "<<rf<<endl;
    //cout <<aIO.getStatus()<<" "<<bIO.getStatus()<<endl;
    //bIO.setPos(0);		
    //read
    //asciiIO_t  rtaIO(file1,mode1);
