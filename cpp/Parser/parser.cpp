/**
 * @file parser.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



void Parser::ParserRun(char* _argv)
{
    if(!(ququ.is_open()))
        throw cant_open_file_e;
    ququ.open(_argv);

    while(getline(ququ,m_line))
    {
        t.Tok(m_line);
    }  
}

