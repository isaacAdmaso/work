/**
 * @file BookManager.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-06
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BMANAGER_H__
#define __BMANAGER_H__

#include <string>
#include <functional>
#include <unordered_map>
#include "Library.h"
#include "Bookrecord.h"


class BookManager_t
{
    friend class Library_t;
private:
    unordered_map<Bookrecord,int> BookrecordHash;
    
public:
    BookManager_t();
    ~BookManager_t();
};

#endif //__BMANAGER_H__