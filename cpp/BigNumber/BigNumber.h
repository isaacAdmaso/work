/**
 * @file BigNumber.h
 * @brief 
 * @version 0.1
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef __BIGNUMBER_H__
#define __BIGNUMBER_H__
#include "../String/String.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class BigNumber
{
private:

    String_t m_number;
    char* strrev(char *str);
    bool IsSmaller(char* num1, char* num2); 
    void findDiff(char* _num1, char* _num2,char* _diff);



public:

    ~BigNumber(){}
    BigNumber(){}
    BigNumber(const char* _number):m_number(_number){}
    BigNumber(int _number){char temp[sizeof(int) + 1];sprintf(temp,"%d",_number);m_number.setString(temp);}
    BigNumber(const BigNumber& _number):m_number(_number.m_number){}

    operator const BigNumber() {return BigNumber(*this);}
    operator int() {return atoi(m_number.getString());}
    bool     operator == (const BigNumber& _n)const{return m_number == _n.m_number;}
    bool     operator <  (const BigNumber& _n)const;
    bool     operator >  (const BigNumber& _n)const;
    const String_t getNumber()const{return m_number;}
    void        setBigNumber(const char* _str){m_number.setString(_str);}
    BigNumber  operator + (const BigNumber& _s);
    BigNumber  operator - (const BigNumber& _s);


};


inline bool     BigNumber::operator <  (const BigNumber& _n)const
{
    if(m_number.getLength() < _n.m_number.getLength()){
        return true;
    }else if(m_number.getLength() > _n.m_number.getLength())
    {
        return false;
    }
    return(strcmp(m_number.getString(), _n.m_number.getString()) < 0) ? true:false;
}

inline bool     BigNumber::operator >  (const BigNumber& _n)const
{
    if(m_number.getLength() > _n.m_number.getLength()){
        return true;
    }else if(m_number.getLength() < _n.m_number.getLength())
    {
        return false;
    }
    return(strcmp(m_number.getString(), _n.m_number.getString()) > 0) ? true:false;
}


ostream&    operator << (ostream& _os,const BigNumber _n);
istream&    operator >> (istream& _is,BigNumber _n);




#endif /*__BIGNUMBER_H__*/