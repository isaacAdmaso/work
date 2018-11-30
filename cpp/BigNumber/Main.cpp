/**
 * @file Main.cpp
 * @brief test Hw
 * @version 0.1
 * @date 2018-11-27
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <stddef.h>
#include <string.h>
#include <iostream>
#include "BigNumber.h"
using namespace std;



int main(int argc, char const *argv[])
{
    int cont = 1;			// trigger to stop loop	
	unsigned int option;
    char inString[MAX];
    BigNumber num1,num2;
    
	while (cont) 
    {
        cout << endl;

		cout << "Choose option: " << endl;
		cout << "1: init 2 Big numbers " << endl;
		cout << "2: print  " << endl;
		cout << "3: check bigger " << endl;
		cout << "4: check smaller " << endl;
		cout << "5:   check equal   " << endl;
		cout << "6:   +   " << endl;
		
        cout << endl;

		cin >>  option;
		switch (option) 
        {
			case 1:
        		cout << "insert 1st Num " << endl;
				cin >> inString;
                num1.setBigNumber(inString);
        		cout << "insert 2nd Num " << endl;
                cin >> inString;
                num2.setBigNumber(inString);
                cout << num1;
                cout << num2;
                break;
			case 2:
                cout << num1;
                cout << num2;
                break;
			case 3:
        		cout << "is first num bigger? " << endl;
                cout << (num1 > num2)<< endl;
                break;
            case 4:
                cout << "is second num bigger? " << endl;
                cout << (num1 < num2)<< endl;
                break;
            case 5:
                cout << "is equals " << endl;
                cout << (num1 == num2)<< endl;
                break;
            case 6:
                cout << " + " << endl;
                cout << (num1 + num2)<< endl;
                break;
			default: 
                cont = 0;	
                break;
		}
	}
    return 0;
}

