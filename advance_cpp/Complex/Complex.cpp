/**
 * @file Complex.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-21
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include "Complex.h"

using namespace std;
int main(int argc, char const *argv[])
{
    Complex<double> a(5.3,4.4),b(4.7,5.6);
    a=b+a;
    cout << a;
    b = 5 + a;
    b = a + 10; 
    cout << ++b;
    cout << (5+a);
    //Complex<double>& c = a+b;
    //b = 5;
    //cout<<c<<endl;
    return 0;
}
