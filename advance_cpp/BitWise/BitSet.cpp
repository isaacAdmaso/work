#include <vector>
#include <iostream>
#include <stdio.h>
#include "mu_test.h"

#include "BitSet.h"


UNIT(XOR)
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
    vec.clear();
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    BitSet<7,unsigned char> c(vec);

    a^=b;
	ASSERT_THAT(a == c);

END_UNIT

UNIT(OR)
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
    vec.clear();
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    BitSet<7,unsigned char> c(vec);


    a|=b;
	ASSERT_THAT(a == c);

END_UNIT


UNIT(AND)
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
    vec.clear();
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(false);
    BitSet<7,unsigned char> c(vec);

    a&=b;
	ASSERT_THAT(a == c);
    
END_UNIT

UNIT(FLIP)
using namespace Advance_Cpp;

    BitSet<9,unsigned char> a;
    a.Set(0);
	ASSERT_THAT(a.Get(0) == 1);
    a.Flip(0);
	ASSERT_THAT(a.Get(0) == 0);
    a.Flip(0);
	ASSERT_THAT(a.Get(0) == 1);


END_UNIT

UNIT(CLEAR)
using namespace Advance_Cpp;

    
    BitSet<5,unsigned char> a;
    a.Set(0);
	ASSERT_THAT(a.Get(0) == 1);
    a.Clear(0);    
	ASSERT_THAT(a.Get(0) == 0);


END_UNIT

UNIT(SET)
using namespace Advance_Cpp;

    BitSet<8,unsigned char> a;
	ASSERT_THAT(a.none());

    a.all();
    a.Set(0);    
    a.Set(1);    
    a.Set(2);    
    a.Set(3);    
    a.Set(4);    
    a.Set(5);    
    a.Set(6);    
    a.Set(7); 
	ASSERT_THAT(a.all());
     
END_UNIT

UNIT(GET)
using namespace Advance_Cpp;

    std::vector<bool> vec;
    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(false);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(true);
    vec.push_back(false);
    BitSet<7,unsigned char> a(vec);
    for(int i = 0;i < 8; ++i)
    {
	    ASSERT_THAT(a.Get(i) == vec.back() );
        vec.pop_back();
    }
END_UNIT

UNIT(ANY)
using namespace Advance_Cpp;
    
    BitSet<7,unsigned char> a;
    ASSERT_THAT(!a.any() );
    a.Set(0);
    ASSERT_THAT(a.any() );


END_UNIT

UNIT(ALL)
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
	ASSERT_THAT(!a.all());
    a.Set(0);    
    a.Set(1);    
    a.Set(2);    
    a.Set(3);    
    a.Set(4);    
    a.Set(5);    
    a.Set(6);    
    a.Set(7); 
	ASSERT_THAT(a.all());
END_UNIT

TEST_SUITE(BITSET)
	TEST(XOR)
	TEST(OR)
	TEST(AND)
	TEST(FLIP)
	TEST(SET)
	TEST(GET)
	TEST(ALL)
	TEST(ANY)

END_SUITE
