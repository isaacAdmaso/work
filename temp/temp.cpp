#include <iostream>

using namespace std;

class Test{
public:
    int* ptr;
    size_t y;
    static int x;
};

int main()
{
    Test t;
    cout<< sizeof(t)<<" ";
    cout<< sizeof(Test *)<< endl;

    return 0;
}
