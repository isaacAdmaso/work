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

#include <istream>
#include "FreqProcessor.h"
#include "uncopy.h"


class Stream : private Uncopy
{
public:
    Stream(std::istream& _source,FreqProcessor& _p):m_input(_source),p(_p){}
    void Load();

private:
    std::istream& m_input;
    FreqProcessor& p;
};


#endif //__STREAM_WH__