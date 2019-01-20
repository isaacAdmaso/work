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
    Shared_ptr <Temp> p2 = p1;
    Shared_ptr <int> p3 = new int(5);
    Shared_ptr <int> p4 = p3;
    Shared_ptr <int> p5 = new int(3);

    cout<<"p3 old: "<<*p3<<endl;
    cout<<"p4 old: "<<*p4<<endl;
    cout<<"p5 old: "<<*p5<<endl;

    p3.swap(p5);

    cout<<"p3 new: "<<*p3<<endl;
    cout<<"p4 new: "<<*p4<<endl;
    cout<<"p5 new: "<<*p5<<endl;


    return 0;
}
