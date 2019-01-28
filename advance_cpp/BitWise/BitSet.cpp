#include "BitSet.h"
#include <vector>


int main()
{
using namespace Advance_Cpp;

    std::vector<bool> vec;
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(false);
    BitSet<7,unsigned char> a(vec);
    vec.clear();
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    BitSet<7,unsigned char> b(vec);
    std::cout << a<<std::endl;
    std::cout << b<<std::endl;
    a^=b;
    std::cout << a<<std::endl;
    a|=b;
    std::cout << a<<std::endl;
    a&=b;
    std::cout << a.Get(0)<<std::endl;
    a.Flip(0);    
    std::cout << a.Get(0)<<std::endl;
    std::cout << a<<std::endl;
    a.Clear(0);    
    std::cout << a<<std::endl;
    std::cout << a.Get(0)<<std::endl;
    a.Set(0);    
    std::cout << a.Get(0)<<std::endl;
    std::cout << a<<std::endl;
    a.Clear(0);    
    std::cout << a<<std::endl;
    a.Set(7);    
    std::cout << a<<std::endl;
    a.Set(0);    
    a.Set(1);    
    a.Set(2);    
    a.Set(3);    
    a.Set(4);    
    a.Set(5);    
    a.Set(6);    
    a.Set(7);    
    std::cout << a<<std::endl;
    std::cout << a.all()<<std::endl;

    return 0;
}