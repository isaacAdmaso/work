/**
 * @file FileOut.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __FILEOUT_H__
#define __FILEOUT_H__
#include <string>
#include <fstream>
#include "Idest.h"
#include "uncopy.h"


class FileOut:public Idest,private Uncopy
{
private:
    std::ofstream m_file; 
    void ErrMsg(const std::string& _errMsg);
public:
    FileOut(const std::string& _fileN);
    virtual ~FileOut();
    virtual void PutString(const std::string& _str);
};




#endif //__FILEOUT_H__
