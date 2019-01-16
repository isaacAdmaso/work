#include <iostream>

using namespace std;

class Test{
public:
    static int x;
    int* ptr;
    int y;
};

int main()
{
    Test t;
    cout<< sizeof(t)<<" ";
    cout<< sizeof(Test *)<< endl;

    return 0;
}
