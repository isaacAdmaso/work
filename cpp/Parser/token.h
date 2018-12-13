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

#include <string>
#include <stack>
#include <vector>
using namespace std;



class Token
{
private:
    static char delimiter[];
    vector<string> m_tContainer;
    
public:

    Token(){}
    ~Token();
    vector<string> Tok(string& _line);
};



Token::~Token()
{
}



#endif //__TOKEN_H__