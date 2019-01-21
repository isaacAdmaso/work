/**
 * @file SingleTone.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <iostream>
#include "SingleTone.h"

using namespace std;
class Foo
{
public:
    void set(int n){m_count = n;}
    void foo(){if(m_count){cout<< "in foo"<<endl;m_count--;}}
    int m_count;
};

int main(int argc, char const *argv[])
{
    SingleTone<Foo>& s1 = SingleTone<Foo>::GetInstance();	// can create many references but to the same object
	s1.m_single.set(2);
    SingleTone<Foo>& s2 = SingleTone<Foo>::GetInstance (); 
    SingleTone<Foo>& s3 = SingleTone<Foo>::GetInstance();	// can create many references but to the same object
	SingleTone<Foo>& s4 = SingleTone<Foo>::GetInstance (); 

    s1.m_single.foo();
    s2.m_single.foo();
    s3.m_single.foo();
    s4.m_single.foo();
	//SingleTone<Foo> s3;		// can't be compiled, CTOR is Private
	//SingleTone<Foo> s3 = s2;  // can't be compiled, copy CTOR is Private
	//s1 = s2;			// can't be compiled, operator= is Private
    return 0;
}
