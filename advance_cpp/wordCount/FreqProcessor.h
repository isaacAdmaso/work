/**
 * @file FreqProcessor.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __FREQ_H__
#define __FREQ_H__

#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "Tokenizer.h"



class FreqProcessor{
public:
    explicit FreqProcessor(Tokenizer& _t):t(_t){}
    ~FreqProcessor(){myMap.clear();}
    void Process(std::string &_s);
    void PrintN(int n);
    typedef std::map<std::string,int>::iterator iter_t;
    typedef std::vector<std::pair<std::string,int> >::iterator iter_v;
    
private:
    std::vector<std::pair<std::string,int> > sortHelp;
    std::map<std::string,int> myMap;
    Tokenizer& t;
    //void Sort();
};


#endif //__FREQ_H__