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
#include <string>
#include <fstream>
#include "uncopy.h"
#include "Isource.h"
#include "ISfactory.h"

class FileIn: public Isource,private Uncopy
{
private:
    std::ifstream m_file; 
    void ErrMsg(const std::string& _errMsg);
public:
    FileIn(const std::string& _fileN);
    virtual ~FileIn();
    virtual std::string GetString();
    virtual void accept(ISfactory  &dispatcher);
};

 



#endif //__FILEIN_H__