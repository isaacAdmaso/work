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


class Analyzer
{
private:
    vector<string> m_tCont;

public:
    Analyzer();
    ~Analyzer();
    void Analyze(vector<string>);
};

Analyzer::Analyzer()
{
}

Analyzer::~Analyzer()
{
}



#endif //__ANALYZE_H__