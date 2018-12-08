/**
 * @file Borrower.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-06
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BORROWER_H__
#define __BORROWER_H__
#include "BorrowerManager.h"
#include <string>
#include <queue>
using namespace std;



class Borrower_t
{
    friend class BorrowerManager_t;
private:
    static int      id;
    string          m_name;
    string          m_phone;
    queue<string>   m_myQ;
    int             m_Id;
public:
    Borrower_t(char* _name, char* _phone):m_name(_name),m_phone(_phone),m_Id(++id){}
    virtual ~Borrower_t() = 0;
    bool addToBorrowed(string& _bookName){}
};
Borrower_t::~Borrower_t(){}


#endif //__BORROWER_H__