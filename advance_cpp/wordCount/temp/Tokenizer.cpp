/**
 * @file Tokenizer.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <string>
#include <algorithm>    // std::find_first_of
#include "Tokenizer.h"
#include <iostream>


std::string Tokenizer::Tokenize( std::string _word){
using namespace std;
    size_t found = -1;

    found = _word.find_first_of(m_delim.c_str());

    while (found != std::string::npos)
    {
        string::iterator iter = _word.begin();
        _word.erase(iter + found);
        found = _word.find_first_of(m_delim.c_str(),found+1);
    }
    return _word;
}
