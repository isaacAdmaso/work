/**
 * @file Tokenizer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __TOKEN_H__
#define __TOKEN_H__
#include <string>


class Tokenizer
{
public:
    Tokenizer(const std::string _delim):m_delim(_delim){}
    std::string Tokenize(std::string _word);

private:
    std::string m_delim;
};



#endif //__TOKEN_H__