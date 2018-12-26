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


std::string Tokenizer::Tokenize( std::string _word){
using namespace std;
    string::iterator iter;

    iter = find_first_of(_word.begin(), _word.end(),m_delim.begin(),m_delim.end());
    if( iter != _word.end()) 
    {
        _word.erase(iter);
    }
    return _word;
}
