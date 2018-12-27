/**
 * @file token.h
 * @brief 
 * @version 0.1
 * @date 2018-12-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __TOKEN_H__
#define __TOKEN_H__
#include <utility> 
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class Token
{
private:
    Token(const Token& _t);
    Token& operator=(const Token& _t);
    const string delimiter;


    
public:
    Token(const std::string& delim):delimiter(delim){}
    vector<std::string>& Tok(vector<std::string>& v,string& word);
};




#endif //__TOKEN_H__