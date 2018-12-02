#include "Car.h"
#include "Bus.h"
#include <iostream>

using namespace std;

int main()
{
    Car_t c;
    Bus_t b;


    cout << b.getCapacity() << " " <<b.getLine()<< " " <<b.getLine()<< " " <<b.getName()<<endl;

    b.setLine(105);
    b.setnSeat(15);
    b.getId();
    b.setBcapacity(1901);
    cout << b.getCapacity() << " " <<b.getLine()<< " " <<b.getnSeat()<< " " <<b.getName()<<endl;


    cout << c.getCapacity() << " " <<c.getSpeed()<< " " <<c.getName()<<endl;
    c.setCcapacity(123);
    c.accelerate(100);
    cout << c.getCapacity() << " " <<c.getSpeed()<< " " <<c.getName()<<endl;


    return 0;
}
