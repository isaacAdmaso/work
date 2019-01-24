/**
 * @file BitWise.h
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
#include <vector>

template<int N>
class BitWise
{
public:
    BitWise();
    BitWise(std::vector<bool>& _boolArray);
    ~BitWise();
    static const int CHAR_SIZE;
private:
    unsigned char* m_Bit;
};

template<int N>
const int BitWise<N>::CHAR_SIZE = 8;

template<int N>
BitWise<N>::BitWise()
{
    int temp;

    if(N % CHAR_SIZE)
        temp = (N / CHAR_SIZE) + 1;
    else
        temp = (N / CHAR_SIZE);
    m_Bit = new unsigned char[temp];
    memset( m_Bit, 0, temp );

}
#endif //__BITWISE_H__