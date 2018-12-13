/**
 * @file main.cpp
 * @brief 
 * @version 0.1
 * @date 2018-12-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>

#include "parser.h"
#include "token.h"

using namespace std;



int main(int argc, char const *argv[])
{
    if(argc < 2)
    {
        cout << "ERR:no excutable file!!!";
        return 1;
    }
    Parser _p();
    for(int i = 1;i < argc; ++i)
    {
        _p.ParserRun(argv[i]);

    }




    return 0;
}

