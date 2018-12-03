#include <iostream>
#include "Car.h"
#include "Bus.h"
#include "BigNumber.h"
#define SIZE 10

using namespace std;

int main()
{
    Car_t c1;
    Car_t c2;
    Bus_t b1;
    Bus_t b2(6);
    BigNumber var = 15,var2 = "47";

    cout << b1.getId() <<" " <<b1.getCapacity()<<" " <<b1.getLine()<< " " <<b1.getnSeat()<< " " <<b1.getName()<<endl;
    cout << b2.getId() << " " << b2.getCapacity() << " " <<b2.getLine()<< " " <<b2.getnSeat()<< " " <<b2.getName()<<endl;

    cout << b1.setLine(var) << endl;
    var2 = var + (BigNumber)4;
    cout << b1.setnSeat(var2) << endl;
    cout << b1.getId() << endl;
    b1.setBcapacity(19);
    cout << b1.setLine(123) << endl;
    cout << b1.getId()<< " " <<b1.getCapacity() << " " <<b1.getLine()<< " " <<b1.getnSeat()<< " " <<b1.getName()<<endl;

    b2.setLine(var);
    var2 = var + (BigNumber)"4";
    b2.setnSeat(var2);
    b2.getId();
    b2.setBcapacity(19);
    b2.setLine(123);
    cout<< b2.getId()<< " "  << b2.getCapacity() << " " << b2.getId()<< " " <<b2.getLine()<< " " <<b2.getnSeat()<< " " <<b2.getName()<<endl;


    cout<< c1.getId()<< " " << c1.getCapacity() << " "  <<c1.getSpeed()<< " " <<c1.getName()<<endl;
    cout << c2.getId() << " "  << c2.getCapacity() << " "  << c2.getId() << " " <<c2.getSpeed()<< " " <<c2.getName()<<endl;

    c1.setCcapacity(12);
    c1.accelerate(var2 -(BigNumber)8);
    cout << c1.getId() << " " << c1.getCapacity()<< " " <<c1.getSpeed()<< " " <<c1.getName()<<endl;

    c2.setCcapacity(12);
    c2.accelerate(var2 -(BigNumber)7);
    cout << c2.getId()  << " " <<c2.getCapacity()<< " " << c2.getSpeed()<< " " <<c2.getName()<<endl;

    
    Car_t* privateArr = new Car_t[SIZE];
    Bus_t* busArr = new Bus_t[SIZE];

    for(int i;i < SIZE;++i)
    {
    cout <<privateArr[i].getName()<< " " << privateArr[i].getId()  << " " << privateArr[i].getCapacity()<< " " <<privateArr[i].getSpeed()<<endl;
    cout <<busArr[i].getName() << " " << busArr[i].getId()<< " " << busArr[i].getCapacity() << " " << busArr[i].getLine()<< " " <<busArr[i].getnSeat()<<endl;

    }

    return 0;
}
