/**
 * @file FreqProcessor.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "FreqProcessor.h"
#include <string>


void FreqProcessor::Process(std::string &_s){
    ++myMap[_s];
}
