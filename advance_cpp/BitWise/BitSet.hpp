/**
 * @file BitSet.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#ifndef __BITSET_HPP__
#define __BITSET_HPP__

namespace Advance_Cpp
{

//template<size_t N,typename T>
//BitSet<N,T>::BitSet()
//{
//}
//

//template<size_t N,typename T>
//BitSet<N,T>::~BitSet()
//{
//}


template<size_t N,typename T>
BitSet<N,T>::BitSet(const BitSet& _bs)
:m_Bit(_bs.m_Bit)
{
}


template<size_t N,typename T>
BitSet<N,T>::BitSet(const std::vector<bool>& _boolArray)
{

    for(unsigned int i = 0; i < N; ++i)
    {
        if(_boolArray[i])
            m_Bit[i/(S(T))] |= 1<<(i%S(T)); 
    }
}

template<size_t N,typename T>
class print
{
public:
    print(std::ostream& _os)
    :m_os(_os){}
    void operator()(const T& _val)
    {
        for(int i = S(_val) - 1; i == 0; --i )
            m_os << (_val & (1 << i)); 
    }
private:
    std::ostream& m_os;
};

template<size_t N,typename T>
std::ostream& BitSet<N,T>::Print(std::ostream& _os)const
{
    print<N,T> p(_os); 
    std::for_each(&m_Bit[0],&m_Bit[NELEMENT(N,S(T))],p);
    return _os;
}


template<size_t N,typename T>
BitSet<N,T>& BitSet<N,T>::operator= (const BitSet& _bs)
{
    std::copy ( _bs.m_Bit, _bs.m_Bit +  NELEMENT(N,S(T)), m_Bit );
} 

template<size_t N,typename T>
class Or
{
public:
    T& operator()(T& m_bit,T& _otherBs)
    {
        return m_bit | _otherBs;
    }

};

template<size_t N,typename T>
BitSet<N,T>& BitSet<N,T>::operator|= (const BitSet& _bs)
{
  std::transform (m_Bit, m_Bit +  NELEMENT(N,S(T)), _bs.m_Bit, Or<N,T>::Or());
}


template<size_t N,typename T>
std::ostream& operator<<(std::ostream& _os, const BitSet<N,T>& _bs)
{
    return _bs.Print(_os);
}


}


#endif //__BITSET_HPP__