#include "Car.h"
#include "Bus.h"
#include "BigNumber.h"
#include <iostream>

using namespace std;

int main()
{
    Car_t c;
    Bus_t b;
    BigNumber var = 105,var2;

    cout << b.getCapacity() << " " <<b.getLine()<< " " <<b.getnSeat()<< " " <<b.getName()<<endl;

    b.setLine(var);
    var2 = var + (BigNumber)4;
    b.setnSeat(var2);
    b.getId();
    b.setBcapacity(19);
    b.setLine(123);
    cout << b.getCapacity() << " " <<b.getLine()<< " " <<b.getnSeat()<< " " <<b.getName()<<endl;


    cout << c.getCapacity() << " " <<c.getSpeed()<< " " <<c.getName()<<endl;
    c.setCcapacity(12);
    c.accelerate(var2 -(BigNumber)88);
    cout << c.getCapacity() << " " <<c.getSpeed()<< " " <<c.getName()<<endl;


    return 0;
}
