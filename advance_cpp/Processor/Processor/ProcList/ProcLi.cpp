/**
 * @file Erase.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __PROCLIST_H__
#define __PROCLIST_H__
#include <vector>
#include <string>
#include <algorithm>
#include "ITx.h"


class Erase: public ITx
{
private:
    static std::string helpDelim;
    std::string m_strDel;
    typedef std::string::iterator iter_t;
public:
    Erase(const std::string strDel)
    :m_strDel(strDel)
    {}
    virtual std::string Processor(const std::string& _str);
    static bool toErase(char ch);
};
std::string Erase::helpDelim = "";
bool Erase::toErase(char ch)
{
    return (helpDelim.find(ch) !=std::string::npos);
}

std::string Erase::Processor(const std::string& _str)
{
    helpDelim = m_strDel; 
    std::string temp = _str;     
    std::remove_if (temp.begin(), temp.end(), toErase);
    return temp;  
}


class Lower: public ITx
{
public:
    virtual std::string Processor(const std::string& _str);
};

std::string Lower::Processor(const std::string& _str)
{
    std::string temp = _str;     
    std::transform(temp.begin(), temp.end(),
    temp.begin(), ::toupper);
    return temp;
}


class Container: public ITx
{
private:
    std::vector<ITx*>  m_container; 
    typedef std::vector<ITx*>::iterator iter_t;

public:
    void AddProc(ITx* _p){m_container.push_back(_p);}
    virtual std::string Processor(const std::string& _str);
};

std::string Container::Processor(const std::string& _str)
{
    std::string temp = _str;  
    for(iter_t it = m_container.begin(); it != m_container.end(); ++it)
    {
        temp = (*it)->Processor(temp);
    }
    return temp;
}


#endif //__PROCLIST_H__