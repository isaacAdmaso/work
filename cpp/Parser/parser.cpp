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



const string Parser::parentheses = "{([<" ;  

Parser::~Parser(){}

void Parser::ParserRun(char* _argv)
{
    int* parenCountAnalyzer;
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
        pLine.first = nLine;
        pLine.second = m_line;
        a.Analyze(t.Tok(pLine));
    }
    parenCountAnalyzer = a.RtParenCount();
    for(int i = 0;i < 4; ++i){
        if(parenCountAnalyzer[i] > 0 ){
            cout << "//error-"<<parenCountAnalyzer[i] << " '"<< parentheses[i]<<"' not closed "<<endl;
        }
    }
}

