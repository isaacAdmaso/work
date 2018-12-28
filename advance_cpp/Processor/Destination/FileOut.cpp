/**
 * @file FileOut.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-28
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include <fstream>
#include "FileOut.h"



void FileOut::ErrMsg(const std::string& _errMsg){
    std::cerr << "Exception " <<_errMsg <<  " file"<< std::endl;
}

FileOut::FileOut(const std::string& _fileN)
{
    try {
        m_file.open(_fileN.c_str());
    } catch (std::fstream::failure e) {
        ErrMsg("open");
    }
}

FileOut::~FileOut()
{
    try {
        m_file.close();
    } catch (std::ifstream::failure e) {
        ErrMsg("close");
    }
}
