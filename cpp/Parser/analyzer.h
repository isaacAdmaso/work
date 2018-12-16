/**
 * @file analyzer.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-13
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __ANALYZE_H__
#define __ANALYZE_H__
#include <vector>
#include <string>
#include <set>
#include <iostream>

using namespace std;


class Analyzer
{
private:
    static const char Predefined_Types[][8];
    static const char Key_words[][16];
    static const char Operators[][8];
    static int PrTypes, Kwords, Op, typeFlag,ifFlag,firstTok,parenCount[4],plus_minusCounter[2];
    static const string TokenString;
    set<string> cTypes;
    set<string> cOper;
    set<string> cKeys;
    set<string> m_tCont;
    typedef typename vector<pair <int ,string> >::iterator	Viter_t;
    typedef set<string>::iterator iter_t;

public:
    
    Analyzer():cTypes(Predefined_Types,Predefined_Types + PrTypes),cOper(Operators ,Operators + Op),cKeys(Key_words,Key_words+Kwords){}
    ~Analyzer(){}
    void Analyze(vector<pair <int ,string> >& _tok);
    int* RtParenCount(){return parenCount;}
};

#endif //__ANALYZE_H__