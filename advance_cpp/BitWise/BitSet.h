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
#include <climits>


#define S(T)           sizeof(T)*CHAR_BIT
#define NELEMENT(x,y) ((x)%(y))?((N / y) + 1):(N / y)
namespace Advance_Cpp
{


template<size_t N,typename T  = size_t>
class BitSet
{
public:
    //BitSet();
    //~BitSet();
    BitSet(const BitSet& _bs);
    explicit BitSet(const std::vector<bool>& _boolArray);
    std::ostream& Print(std::ostream& _os)const;

	BitSet& operator= (const BitSet& _bs); 
	BitSet& operator|=(const BitSet& _bs);
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
};

}

#include "BitSet.hpp"

#endif //__BITWISE_H__