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
//include 
#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;



   

void Parser::ParserRun(char* _argv)
{
    ququ.open(_argv);
    if(!(ququ.is_open()))
        throw cant_open_file_e;
    
    pair <int ,string> pLine;
    int nLine = 0 ;
    
    while (getline(ququ,m_line)) {
        ++nLine;
        if (m_line.empty() || (m_line.length() == 1 && isspace(m_line[0]))) {
            continue;
        }
        //if(isspace(m_line[m_line.length() - 1 ]))
        //    m_line[m_line.length() - 1] = '\0';
        //
        pLine.first = nLine;
        pLine.second = m_line;
        a.Analyze(t.Tok(pLine));
    }  
}

