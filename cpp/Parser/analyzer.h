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
#include <iostream>

using namespace std;


class Analyzer
{
private:
    vector<string> m_tCont;
    typedef typename vector<pair <int ,string> >::iterator	iter_t;
    static char Predefined_Types[][8];
    static char Key_words[][16];
    static char Operators[][8];

public:
    Analyzer(){}
    ~Analyzer(){}
    void Analyze(vector<pair <int ,string> >& _tok);
};




#endif //__ANALYZE_H__