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


bool BigNumber::IsSmaller(BigNumber _num1, BigNumber _num2) 
{ 
    int n1 = _num1.getNumber().getLength(), n2 = _num2.getNumber().getLength(),i; 
    char num1,num2;

    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (i = 0; i < n1; i++) {
        num1 = _num1.getNumber().getString()[i];
        num2 = _num2.getNumber().getString()[i]; 
        if (num1 < num2) {
            return true; 
        }  else if (num1 > num2){
            return false; 
        }
    }
    return false; 
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
    if(IsSmaller(longString,shortString)){
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
/*
BigNumber  BigNumber::operator - (const BigNumber& _n){
    char aStr[MAX], bStr[MAX],ans[MAX],*shortString,*longString;
    int alen, blen,i,sub,carry = 0,flag = 0;

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
        flag = 1;
    }
    ans[alen + 1]=ans[alen]=ans[alen - 1]='\0';
    for(i = 0;i < alen;++i){
        sub = C2D(longString[i]) - ((i<blen) ? C2D(shortString[i]): 0) - carry;
        if(sub < 0)
        {
            carry = 1; 
            sub = - sub;
        }else{
            carry = 0;
        }
        ans[i] = D2C(sub);
    }
    if(flag || carry)
    {
        ans[i++]='-';
    }
    BigNumber rtVal(strrev(ans));
    return rtVal;
}
*/
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

