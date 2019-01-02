/**
 * @file test.cpp\
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <cstring>
#include <iostream>
#include "Fib.h"

#define TOFIB 45

int main(int argc, char const *argv[])
{
    int numTfib;
    Fib f;

    if(argc == 2)
        numTfib = atoi(argv[1]); 
    else
        numTfib = TOFIB;

    std::cout << f.Get_Fib(numTfib) << std::endl;

    for(int i = numTfib; i >= 0 ; --i)
        std::cout << f.Get_Fib(i) << std::endl;


    return 0;
}

