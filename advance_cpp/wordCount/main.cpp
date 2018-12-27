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
#include <string>
#include <iostream>
#include <fstream>
#include "token.h"
#include "FreqProcessor.h"
#include "Stream.h"

const std::string deli = "/";

int main ( int argc, char const *argv[]){
    if(argc < 3)
        return 1;
    const int i = atoi(argv[2]);
    std::ifstream f(argv[1],std::ifstream::in);
    Token t(deli);
    FreqProcessor p(t);
    Stream s(f,p);
    s.Load();
    s.Print((int)i);
    return 0;
}
//hello
//hello
//hello
//hello
//hello
//hello
//hello
//hello
//hello
//hello
//hello
//hello