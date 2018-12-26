/**
 * @file Stream.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-26
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __STREAM_WH__
#define __STREAM_WH__

#include <iostream>
#include "FreqProcessor.h"




class Stream{
private:
    istream& m_input;
    FreqProcessor p;

public:
    ~Stream(){}
    Stream(istream& _source,const FreqProcessor& _p):m_input(_source),p(_p){}
    void Load();
};


#endif //__STREAM_WH__