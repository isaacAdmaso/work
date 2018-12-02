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
    int cont = 1, cont2;			// trigger to stop loop	
	unsigned int option;
    BigNumber num1;
    BigNumber num2;
    char inString[MAX];
    
	while (cont) 
    {
        cout << "init 2 Big numbers " << endl;
        cout << "insert 1st Num " << endl;
        cin >> inString;
        num1.setBigNumber(inString);
        cout << "insert 2nd Num " << endl;
        cin >> inString;
        num2.setBigNumber(inString);
        cout << "the two numbers are:"<< endl;
        cout << num1<< endl;
        cout << num2<< endl;
        cont2 = 1;
		while(cont2)
        {
            cout << "Choose option: " << endl;
		    cout << "1: print  " << endl;
		    cout << "2: check bigger " << endl;
		    cout << "3: check smaller " << endl;
		    cout << "4: check equal   " << endl;
		    cout << "5: +   " << endl;
		    cout << "6: -   " << endl;
		    cout << "7: new numbers   " << endl;
		    cout << "Any another number - stop " << endl;
    
            cout << endl;

		    cin >>  option;
		    switch (option) 
            {
		    	case 1:
                    cout << num1<<endl;
                    cout << num2<<endl;
                    break;
		    	case 2:
            		cout << "is first num bigger? " << endl;
                    cout << (num1 > num2)<< endl;
                    break;
                case 3:
                    cout << "is second num bigger? " << endl;
                    cout << (num1 < num2)<< endl;
                    break;
                case 4:
                    cout << "is equals " << endl;
                    cout << (num1 == num2)<< endl;
                    break;
                case 5:
                    cout << " + " << endl;
                    cout << (num1 + num2)<< endl;
                    break;
                case 6:
                    cout << " - " << endl;
                    cout << (num1 - num2)<< endl;
                    break;
                case 7:
                    cont2 = 0;	
                    break;
		    	default:
                    cont2 = 0;	
                    cont = 0;	
                    break;
		    }
        }
	}
    return 0;
}

