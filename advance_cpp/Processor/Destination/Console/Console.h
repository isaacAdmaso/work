/**
 * @file Console.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CONSOLEOUT_H__
#define __CONSOLEOUT_H__

#include <string>
#include <ostream>
#include "uncopy.h"
#include "Idest.h"



class Console: public Idest,private Uncopy
{
private:
    std::ostream& m_console;

public:
    Console(std::ostream& _cout);  
    virtual void PutString(const std::string& _str);
};



#endif //__CONSOLEOUT_H__