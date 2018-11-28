/**
 * @file Main.cpp
 * @brief test Hw
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stddef.h>
#include <string.h>
#include <iostream>
#include "String.h"


#define MAX 1024

int main(int argc, char const *argv[])
{
    

    size_t len;
    int cmpSval = -2;

    
    String_t str1;
    String_t str2("hslfkgnls");
    String_t& str4 = str2; 
    String_t str3(str4);


    str1 = str2;

    len = str2.getLength();

    std::cout << len;

    str4.setString("sodkgf");

    std::cout << "\n" << str2.getString() << "\n";

    cmpSval = str4.cmpString(str1);

    std::cout  << "\n" << cmpSval << "\n";

    str1.printString();
    str2.printString();
    str3.printString();
    str4.printString();

    std::cout <<"&str2 "<< &str2 << "\n&str4 "<< &str4 << "\n";

    return 0;
}

