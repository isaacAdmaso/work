/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include "FreqProcessor.h"
#include "Stream.h"



int main(int argc, char const *argv[]){
    if(argc < 2)
        return 1;
    ifstream f(argv[1]);
    FreqProcessor p;
    Stream(f,p);

    return 0;
}
