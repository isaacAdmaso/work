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



class FreqProcessor{
private:
    std::map<std::string,int> myMap;
    typedef std::map<std::string,int>::iterator iter_t;

    
public:
    FreqProcessor(){}
    ~FreqProcessor(){myMap.clear();}
    void Process(std::string &_s);
};


#endif //__FREQ_H__