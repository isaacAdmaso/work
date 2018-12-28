/**
 * @file Erase.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __ERASE_H__
#define __ERASE_H__
#include <string>
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

#endif //__ERASE_H__