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
#include <iterator>
#include "FreqProcessor.h"


void FreqProcessor::Process(std::string &_s){
    vector<std::string> temp;
    
    
    temp = t.Tok(temp,_s);
    int len = (int)temp.size();
    for(int i = 0; i < len; ++i){
        std::string toMap = temp[i];
        ++myMap[toMap];
    }
}
bool FreqProcessor::cmp(const std::pair<std::string,int>  &p1, const std::pair<std::string,int> &p2){
    return p2.second < p1.second;
}


void FreqProcessor::PrintN(int n){
using namespace std;

    vector<pair<std::string,int> > v;

    copy(myMap.begin(), myMap.end(), back_inserter(v));

    sort(v.begin(), v.end(), cmp);

    for(unsigned int i = 0; (i < v.size() && n); ++i, --n)
        cout << v[i].first << " : " << v[i].second << endl;
}







//    Sort();

    //for (;(it != sortHelp.end) && (n);++it , --n){
    //    if(n == 0)
    //        break;
    //    std::cout << (*it).first << " :: " << (*it).second << std::endl;
    //}
 

//
//class Word
//{
//public:
//    Word(std::pair<std::string,int> _p):p(_p.first,_p.second){}
//    Word(const Word& _p):p(_p.p.first,_p.p.second){}
//    bool operator<(const Word& secondW){return p.second < secondW.p.second;};
//    Word& operator=(Word& _other){
//        if(this != &_other){
//            p.first = _other.p.first;
//            p.second = _other.p.second;
//        }
//        return *this;
//    }
//    std::pair<std::string,int> p;
//    
//private:
//};


//void FreqProcessor::Sort(){
//    std::vector<Word> v;
//
//    std::copy ( myMap.begin(), myMap.end(), v.begin() );
//
//    sort(v.begin(), v.end());
//   // std::copy ( v.begin(), v.end(), sortHelp.begin() );
//    
//}