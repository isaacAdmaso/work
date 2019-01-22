#include <iostream>
#include "Shared_ptr.h"


void swap(Shared_ptr <int>& _a, Shared_ptr <int>& _b)
{
    int temp = *_a;
    *_a = *_b;
    *_b = temp;

}  

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
    p2->foo();
    Shared_ptr <int> p3 = new int(5);
    Shared_ptr <int> p4 = p3;
    Shared_ptr <int> p5 = new int(3);

    //check operator *()const!!(on gdb)
    p4 =\
     p3;    

    cout<<"p3 old: "<<*p3<<endl;
    cout<<"p4 old: "<<*p4<<endl;
    cout<<"p5 old: "<<*p5<<endl;

    swap(p3,p5);
    cout<<"p3 new: "<<*p3<<endl;
    cout<<"p4 new: "<<*p4<<endl;
    cout<<"p5 new: "<<*p5<<endl;

    Shared_ptr<float> f1;
    *f1 = 15;
    cout << *f1<<endl;

    return 0;
}
