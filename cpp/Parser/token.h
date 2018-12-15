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
    vector<pair <int ,string> > m_vec;
    string m_line;
    Token(const Token& _t);
    Token& operator=(const Token& _t);
    static string delimiter;


    
public:
    Token(){}
    ~Token(){}
    vector<pair <int ,string> >& Tok(pair <int ,string>& pLine);
};




#endif //__TOKEN_H__