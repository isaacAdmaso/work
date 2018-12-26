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
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include "FreqProcessor.h"


void FreqProcessor::Process(std::string &_s){
    std::string temp = t.Tokenize(_s);
    ++myMap[t.Tokenize(_s)];
}


class Word
{
public:
    Word(std::pair<std::string,int> _p):p(_p.first,_p.second){}
    bool operator<(const Word& secondW){return p.second < secondW.p.second;};
    
private:
    std::pair<std::string,int> p;
};


//void FreqProcessor::Sort(){
//    std::vector<Word> v;
//
//    std::copy ( myMap.begin(), myMap.end(), v.begin() );
//
//    sort(v.begin(), v.end());
//   // std::copy ( v.begin(), v.end(), sortHelp.begin() );
//    
//}

void FreqProcessor::PrintN(int n){
    //iter_v it = sortHelp.begin();

//    Sort();

    //for (;(it != sortHelp.end) && (n);++it , --n){
    //    if(n == 0)
    //        break;
    //    std::cout << (*it).first << " :: " << (*it).second << std::endl;
    //}
//}
 