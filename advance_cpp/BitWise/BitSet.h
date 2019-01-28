/**
 * @file BitSet.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-24
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __BITWISE_H__
#define __BITWISE_H__
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>//CHAR_BIT


#define S(T)           (sizeof(T)*CHAR_BIT)
#define NELEMENT(x,y) (((x)%(y))?((x / y) + 1):(x / y))
namespace Advance_Cpp
{


template<size_t N,typename T  = size_t>
class BitSet
{
public:
    BitSet();
    BitSet(const BitSet& _bs);
	BitSet& operator=(const BitSet& _bs);
    explicit BitSet(const std::vector<bool>& _boolArray);
    void Print(std::ostream& _os)const;

	BitSet& operator|=(const BitSet& _bs);
	BitSet& operator^=(const BitSet& _bs);
	BitSet& operator&=(const BitSet& _bs);
	BitSet& operator<<=(size_t _nos); 
	
    bool Get(size_t _index) const;
	void Set(size_t _index);
	void Clear(size_t _index);
	void Flip(size_t _index);

	bool all() const;
	bool any() const;
private:
    T m_Bit[ NELEMENT(N,S(T))];
	T* begin();
	T* end();
	const T* begin() const;
	const T* end() const;
};


template<size_t N,typename T>
T* BitSet<N,T>::begin()
{
	return m_Bit;
}

template<size_t N,typename T>
T* BitSet<N,T>::end()
{
	return m_Bit+NELEMENT(N,S(T));
}



template<size_t N,typename T>
const T* BitSet<N,T>::begin() const
{
	return m_Bit;
}

template<size_t N,typename T>
const T* BitSet<N,T>::end() const
{
	return m_Bit+NELEMENT(N,S(T));
}

template<size_t N,typename T>
BitSet<N,T>::BitSet()
{
	std::fill(begin(),end(),0); 
}

template<size_t N,typename T>
BitSet<N,T>::BitSet(const BitSet& _bs)
{
	std::copy ( _bs.begin(), _bs.end(), begin()); 
}


template<size_t N,typename T>
BitSet<N,T>& BitSet<N,T>::operator=(const BitSet& _bs)
{
	if(*this != _bs)
	{
		std::copy ( _bs.begin(), _bs.end(),begin()); 
	}
	return *this;
}


template<size_t N,typename T>
BitSet<N,T>::BitSet(const std::vector<bool>& _boolArray)
{
    size_t size = _boolArray.size();

    for(size_t i = 0; i < size; i+=S(T))
    {
        T c = 0;
        for(size_t j = 0 ; (j < S(T))&&(j < (size - i)); ++j)
        {
            if(_boolArray[i + j])
                c |= T(1<<(S(T) - 1 - j)); 

        }
        m_Bit[i/S(T)] = c;
    }
}

namespace BitSet_imp
{

template<typename T>
struct Or
{
    T operator()(const T& m_bit,const T& _otherBs)
    {
        return m_bit | _otherBs;
    }

};


template<typename T>
struct XOr
{
    T operator()(const T& m_bit,const T& _otherBs)
    {
        return m_bit ^ _otherBs;
    }

};


template<typename T>
struct And
{
    T operator()(const T& m_bit,const T& _otherBs)
    {
        return m_bit & _otherBs;
    }

};


template<typename T>
class Print
{
public:
    Print(std::ostream& _os)
    :m_os(_os){}
    void operator()(const T& _val)const
    {
        for(int i = S(T) - 1; i >= 0; --i )
            m_os << ((_val & (T(1) << i))? "1" : "0") <<"|";
    }
private:
    std::ostream& m_os;
};

}

template<size_t N,typename T>
BitSet<N,T>& BitSet<N,T>::operator|= (const BitSet& _bs)
{
  	std::transform (begin(), end(), _bs.begin(),begin(), BitSet_imp::Or<T>());
  	return *this;
}


template<size_t N,typename T>
BitSet<N,T>& BitSet<N,T>::operator^= (const BitSet<N,T>& _bs)
{
  	std::transform (begin(), end(), _bs.begin(),begin(), BitSet_imp::XOr<T>());
  	return *this;
}


template<size_t N,typename T>
BitSet<N,T>& BitSet<N,T>::operator&= (const BitSet& _bs)
{
  	std::transform (begin(), end(), _bs.begin(),begin(), BitSet_imp::And<T>());
  	return *this;
}


template<size_t N,typename T>
void BitSet<N,T>::Print(std::ostream& _os)const
{
    std::for_each(begin(),end(),BitSet_imp::Print<T>(_os));
}


template<size_t N,typename T>
std::ostream& operator<<(std::ostream& _os, const BitSet<N,T>& _bs)
{
	_bs.Print(_os);
    return _os; 
}


template<size_t N,typename T>
bool BitSet<N,T>::Get(size_t _index) const
{
  return (m_Bit[_index / S(T)] & (T(1) << (_index % S(T))));
}


template<size_t N,typename T>
void BitSet<N,T>::Set(size_t _index)
{
  m_Bit[_index/S(T)] |= T(1 << (_index%S(T)));
}

template<size_t N,typename T>
void BitSet<N,T>::Clear(size_t _index) 
{
  	m_Bit[_index/S(T)] &= T(~(1 << (_index%S(T))));
}


template<size_t N,typename T>
void BitSet<N,T>::Flip(size_t _index) 
{
  	m_Bit[_index/S(T)] ^= T(1 <<(_index%S(T)));
}

}

//#include "BitSet.hpp"

#endif //__BITWISE_H__