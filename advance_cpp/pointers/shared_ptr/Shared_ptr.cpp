#include <iostream>
#include "Shared_ptr.h"



class Temp
{
public:
    void foo(){std::cout<<"in Temp class in foo "<<std::endl;}
};

int main(int argc, char const *argv[])
{
using namespace std;

    //Auto_Ptr <int> p1 = new int(5);
    //cout<<endl<<*p1<<endl;
    Shared_ptr <Temp> p1 = new Temp;
    p1->foo();
    return 0;
}
