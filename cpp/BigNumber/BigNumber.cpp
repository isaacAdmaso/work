/**
 * @file BigNumber.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2018-11-30
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "BigNumber.h"

using namespace std;
#define C2D(C) ((C)-'0')
#define D2C(C) ((C)+'0')


istream& operator >> (istream& _os,BigNumber _n)
{
    _os >> _n.getNumber();
    return _os;
}

ostream&  operator << (ostream& _os,const BigNumber _n)
{
    _os << _n.getNumber();
    return _os;
}

BigNumber  BigNumber::operator + (const BigNumber& _n){
    char aStr[MAX], bStr[MAX],ans[MAX],*shortString,*longString;
    int alen, blen,i,sum,carry = 0;

    strcpy(aStr,m_number.getString());
    strcpy(bStr,_n.m_number.getString());
    alen = strlen(strrev(aStr));
    longString = aStr;
    blen = strlen(strrev(bStr));
    shortString = bStr;
    if(alen<blen){
        alen ^= blen;blen ^= alen;alen ^= blen;//swap
        longString = bStr;
        shortString = aStr;
    }
    ans[alen+1]=ans[alen]='\0';
    for(i = 0;i < alen;++i){
        sum = C2D(longString[i]) + ((i<blen) ? C2D(shortString[i]): 0)+carry;
        ans[i] = D2C(sum % 10);
        carry = sum / 10;
    }
    if(carry){
        ans[i++]='1';
    }
    BigNumber rtVal(strrev(ans));
    return rtVal;
}

char *BigNumber::strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

