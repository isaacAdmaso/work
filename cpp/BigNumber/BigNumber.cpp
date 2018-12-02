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


bool BigNumber::IsSmaller(char* _num1, char* _num2) 
{ 
    int n1 = strlen(_num1), n2 = strlen(_num2),i; 
    char num1,num2;

    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (i = 0; i < n1; i++) {
        num1 = _num1[i];
        num2 = _num2[i]; 
        if (num1 < num2) {
            return true; 
        }  else if (num1 > num2){
            return false; 
        }
    }
    return false; 
} 


BigNumber  BigNumber::operator + (const BigNumber& _n)\
{
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

void BigNumber::findDiff(char* _num1, char* _num2,char* _diff)
{
    int sub,i,n1,n2,carry,addMinus = 0;
    if (IsSmaller(_num1, _num2))
    {
        char* temp = _num1;
        _num1 = _num2;
        _num2 = temp;
        addMinus = 1;
          
    } 
    n1 = strlen(_num1);
    n2 = strlen(_num2); 
    strrev(_num1);
    strrev(_num2);
    carry = 0;
    for (i=0; i<n2; ++i) 
    { 
        sub = ((_num1[i]-'0')-(_num2[i]-'0')-carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        _diff[i] = sub + '0'; 
    } 
    for (i = n2; i < n1; ++i) 
    { 
        sub = ((_num1[i]-'0') - carry); 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        _diff[i] = sub + '0'; 
    }
   if(addMinus)
   {
        _diff[strlen(_diff)] = '-';
        _diff[strlen(_diff)+1] = '\0';
   }
   _diff =  strrev(_diff);
} 

BigNumber  BigNumber::operator - (const BigNumber& _n){
    char ans[MAX], num1[MAX],num2[MAX]; 
    strcpy(num1,m_number.getString());
    strcpy(num2,_n.m_number.getString());
    findDiff(num1,num2,ans);
    BigNumber rtVal(ans);
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

