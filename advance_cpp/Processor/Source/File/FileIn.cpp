/**
 * @file FileIn.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "FileIn.h"
#include <iostream>
#include <fstream>


void FileIn::ErrMsg(const std::string& _errMsg){
    std::cerr << "Exception " <<_errMsg <<  " file"<< std::endl;
}


FileIn::FileIn(const std::string& _fileN)
{
    try {
        m_file.open(_fileN.c_str());
    } catch (std::ifstream::failure e) {
        ErrMsg("open");
    }
}

FileIn::~FileIn()
{
    try {
        m_file.close();
    } catch (std::ifstream::failure e) {
        ErrMsg("close");
    }
}

std::string FileIn::GetString()
{
    std::string tempLine;
    if( !m_file.eof() )
    {
        try 
        {
            std::getline (m_file, tempLine, ' ');
            while (!tempLine.length())
                std::getline(m_file, tempLine, ' '); 

        } catch (std::ifstream::failure e) {
            ErrMsg("GetString");
        }
    }
    return tempLine;
}
