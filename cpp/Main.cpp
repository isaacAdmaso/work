/**
 * @file Main.cpp
 * @brief test Hw
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "String.h"
#include <string.h>
#include <iostream>
#include <stddef.h>

#define MAX 1024


int main()
{
    size_t len;
    int cmpSval = -2;
    char rtString[MAX];

    
    String_t str1;
    String_t str2("yitshak");
    String_t& str4 = str2; 
    String_t str3(str4);


    str1 = str2;

    len = str2.getLength();

    std::cout << len;

    str4.setString("admaso");

    strcpy(rtString,str2.getString());

    std::cout << "\n" << rtString << "\n";

    cmpSval = str1.cmpString(str4);

    std::cout  << "\n" << cmpSval << "\n";

    str1.printString();
    str2.printString();
    str3.printString();
    str4.printString();

    return 0;
}
