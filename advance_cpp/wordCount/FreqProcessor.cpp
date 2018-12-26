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
#include <iostream>
#include "FreqProcessor.h"


void FreqProcessor::Process(string &_s){
    iter_t itr;

    itr = myMap.find(_s);
    (itr != myMap.end()) ? (++myMap[_s]) : ( myMap[_s] = 1);  
    cout<< _s<<endl;  
}
