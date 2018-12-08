/**
 * @file BorrowerManager.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-08
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BORROWERMANAGER_H__
#define __BORROWERMANAGER_H__
#include <string>
#include <functional>
#include <unordered_map>
#include "Library.h"


class BorrowerManager_t
{
    friend class Library_t;
private:
    unordered_map<Borrower_t,int> BorrowerHash;
    
public:
    ~BorrowerManager_t() = 0;
    BorrowerManager_t();
    bool addBorrower(string& _bookName);
};


BorrowerManager_t::~BorrowerManager_t(){}

#endif //__BORROWERMANAGER_H__