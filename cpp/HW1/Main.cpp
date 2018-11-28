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
using namespace std;



int main(int argc, char const *argv[])
{
    

    size_t len;
    int cmpSval = -2;

    
    String_t str1;
    String_t str2("Yitshak");
    String_t& str4 = str2; 
    String_t str3(str4);


    str1 = str2;

    len = str2.getLength();

    std::cout << "length " <<len;

    str4.setString("Admaso");

    std::cout << "\n" << str2 << "\n";

    cmpSval = str4.cmpString(str1);

    std::cout  << "compare value " << cmpSval << endl;

    cout << str1;
    str1.lower();
    cout << str1;
    cout << str2;
    str2.upper();
    cout << str2;
    cout <<str4;
    str2.lower();
    cout << str2;
    str4.prepend("str3");
    cout <<str3;
    cout <<str4;
    str4 += str3;
    str4 += "str3";

    cout <<str4;
    str4.upper();
    cout <<str4;
    cout <<str1;

    cout << (str4 < str1) << endl;
    cout << (str4 >= str2) << endl;
    cout << (str4 == str2) << endl;
    cout << (str4 <= str2) << endl;
    cout << (str4 != str1) << endl;
    cout << (str4 > str1) << endl;
    cout << (str4 < str2) << endl;
    cout << (str4 != str2) << endl;
    cout << (str4 == str1) << endl;
    cout <<"contains " <<(str4.contains(str1.getString())) << endl;
    str4.lower();
    cout <<"contains " <<(str4.contains(str1.getString())) << endl;
    cout << (str4[str4.getLength()]) << endl;
    cout << str4;
    cout << (str4[str4.getLength() - 3]) << endl;
    cout << (str4[0]) << endl;

    return 0;
}

