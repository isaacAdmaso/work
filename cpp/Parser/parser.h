/**
 * @file parser.h
 * @brief 
 * @version 0.1
 * @date 2018-12-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "token.h"
#include "analyzer.h"

using namespace std;

class Parser
{
private:
    ifstream ququ;
    string m_line;
    static const string parentheses;
    Token t;
    Analyzer a;


public:
    enum i_state{
        ok_e, 
		cant_open_file_e, 
		bad_access_e,
        readErr_e
    };
    virtual ~Parser();
    Parser(){}
    void ParserRun(char* _argv);
};




#endif //__PARSER_H__

