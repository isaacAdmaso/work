/**
 * @file predicate.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-12-11
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef __PREDICATE_H__
#define __PREDICATE_H__


template <class T>
class predicate
{
private:
    T val;
public:
    ~predicate(){}
    predicate(const T& _item):val(_item){}
    bool operator ()(T* _ptr) {return *_ptr == val;}
};

#endif //__PREDICATE_H__