/**
 * @file Stream.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "Stream.h"
#include <string>

using namespace std;


void Stream::Load(){
    string word;

    while ((m_input >> word) && m_input.good()) {
        if (word.empty() || (word.length() == 1 && isspace(word[0]))) {
            continue;
        }
        p.Process(word);
    }
}