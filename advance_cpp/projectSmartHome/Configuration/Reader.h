/**
 * @file READER.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-08
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __READER_H__
#define __READER_H__
#include <string>
#include <vector>


class Reader
{
public:
    Reader(const std::string& _config,std::vector<std::string>& _configVec);

private:
    void CreateFrom(const std::string& _config,std::vector<std::string>& _configVec);
};





#endif //__READER_H__