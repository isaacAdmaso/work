/**
 * @file Complex.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>

template<class T>
class Complex
{
public:
    Complex(const T& _real, const T& _imag = 0)
    :m_real(_real),m_imag(_imag)
    {
    }
    Complex(const Complex<T>& other)
    :m_real(other.m_real),m_imag(other.m_imag)
    {
    }
    ~Complex(){}
    std::ostream& print(std::ostream& _os)const{_os<<"imaginary: "<<m_imag<<std::endl<<"real: "<<m_real<<std::endl;return _os;}
    Complex<T>& operator=(const Complex<T>& _other){m_real = _other.m_real;m_imag = _other.m_imag;return *this;}
    friend Complex<T> operator++(Complex<T>& _z){return _z.m_real++,_z;} 
    friend Complex<T> operator--(Complex<T>& _z){return _z.m_real--,_z;}
    friend Complex<T> operator+(Complex<T> _a,const Complex<T>& _b){return _a += _b;} 
    friend Complex<T> operator-(Complex<T> _a,const Complex<T>& _b){return _a -= _b;} 
    friend Complex<T> operator++(Complex<T>& _z,int){Complex<T> temp = _z;_z.m_real++;return temp;} 
    friend Complex<T> operator--(Complex<T>& _z,int){Complex<T> temp = _z;_z.m_real++;return temp;}
    Complex<T>& operator+=(const Complex<T>& _other){m_real += _other.m_real;m_imag += _other.m_imag;return *this;} 
    Complex<T>& operator-=(const Complex<T>& _other){m_real -= _other.m_real;m_imag -= _other.m_imag;return *this;} 
private:
    T m_real,m_imag;
};

template<class T>
std::ostream& operator << (std::ostream& _os,const Complex<T>& _z)
{
    return _z.print(_os);
}

#endif //__COMPLEX_H__

