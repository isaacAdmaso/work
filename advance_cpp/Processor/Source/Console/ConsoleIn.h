/**
 * @file ConsoleIn.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __CONSOLEIN_H__
#define __CONSOLEIN_H__

#include <string>
#include <istream>
#include "uncopy.h"
#include "Isource.h"
#include "ISfactory.h"


class ConsoleIn: public Isource,private Uncopy
{
private:
    std::istream& m_console;

public:
    ConsoleIn(std::istream& _cin);
    virtual std::string GetString();
    virtual void accept(ISfactory  &dispatcher);
};



#endif //__CONSOLEIN_H__