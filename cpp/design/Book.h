/**
 * @file Book.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-06
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __BOOK_H__
#define __BOOK_H__

#include <string>

using namespace std;


class Book_t
{
private:
    string   m_title;
    string   m_author;
    string   m_ISBN;
public:
    Book_t();
    Book_t(string& _title, string& _author,string& m_isbn):m_title(_title),m_author(_author),m_ISBN(m_isbn){}
    Book_t(Book_t& _book);
    ~Book_t();
};


#endif //__BOOK_H__