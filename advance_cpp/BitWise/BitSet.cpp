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
    vec.push_back(true);
    BitSet<7> b(vec);
    std::cout << b;

    return 0;
}