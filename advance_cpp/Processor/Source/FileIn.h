/**
 * @file FileIn.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __FILEIN_H__
#define __FILEIN_H__
#include "Isource.h"
#include "uncopy.h"
#include <string>
#include <fstream>

class FileIn: public Isource,private Uncopy
{
private:
    std::ifstream m_file; 
public:
    FileIn();
    virtual ~FileIn();
    virtual std::string GetString();
};

 



#endif //__FILEIN_H__