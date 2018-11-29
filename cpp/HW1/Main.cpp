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
#include "String.h"
using namespace std;



int main(int argc, char const *argv[])
{
    int cont = 1;			// trigger to stop loop	
	unsigned int option;
    char inString[MAX];
    size_t idx;
    String_t str1, str2;
	String_t::caseSens = false;
	while (cont) 
    {
		cout << "Choose option: " << endl;
		cout << "1: init 2 String_t class object  " << endl;
		cout << "2: print  " << endl;
		cout << "3: prepend " << endl;
		cout << "4:   !=  " << endl;
		cout << "5:   <   " << endl;
		cout << "6:   >   " << endl;
		cout << "7:   >=  " << endl;
		cout << "8:   <=  " << endl;
		cout << "9:   ==  " << endl;
		cout << "10:  []  " << endl;
		cout << "11: is contains?  " << endl;
		cout << "12: converts string to upper cases " << endl;
		cout << "13: converts string to lower cases " << endl;
		cout << "Any another number - stop " << endl;

		cin >>  option;
		switch (option) 
        {
			case 1:
        		cout << "insert 1st string " << endl;
				cin >> inString;
                str1.setString(inString);
        		cout << "insert 2nd string " << endl;
                cin >> inString;
                str2.setString(inString);
                str2[4] = 'r';
                cout << str2;
                break;
			case 2:
                cout << str1;
                cout << str2;
                break;
			case 3:
        		cout << "prepend to 1st " << endl;
                cin >> inString;
                str1.prepend(inString);
                cout << "prepend to 2nd " << endl;
                cin >> inString;
                str2.prepend(inString);
                break;
            case 4:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "2nd string " << endl;
                cin >> inString;
                str2.setString(inString);
                cout << (str1 != str2) << endl;
                break;
            case 5:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "2nd string " << endl;
                cin >> inString;
                str2.setString(inString);
                cout << "1st string < 2nd string: "<<(str1 < str2) << endl;
                break;
            case 6:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "2nd string " << endl;
                cin >> inString;
                str2.setString(inString);
                cout << "1st string > 2nd string: "<<(str1 > str2) << endl;
                break;
            case 7:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "2nd string " << endl;
                cin >> inString;
                str2.setString(inString);
                cout << "1st string >= 2nd string: "<<(str1 >= str2) << endl;
                break;
            case 8:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "2nd string " << endl;
                cin >> inString;
                str2.setString(inString);
                cout << "1st string <= 2nd string: "<<(str1 <= str2) << endl;
                break;
            case 9:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "2nd string " << endl;
                cin >> inString;
                str2.setString(inString);
                cout << "1st string == 2nd string: "<<(str1 == str2) << endl;
                break;
            case 10:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "index" << endl;
                cin >> idx;
                cout << "char in place: "<< idx << " is:" << str1[idx] << endl;
                break;
            case 11:
                cout << "1st string " << endl;
                cin >> inString;
                str1.setString(inString);
                cout << "2nd string " << endl;
                cin >> inString;
                cout << "is 1st string contains 2nd string: "<<(str1.contains(inString)) << endl;
                break;
            case 12:
                cout << " string to convert" << endl;
                cin >> inString;
                str1.setString(inString);
                cout <<  str1 << endl;
                str1.upper();
                cout << str1 << endl;
                break;

            case 13:
                cout << " string to convert" << endl;
                cin >> inString;
                str2.setString(inString);
                cout <<  str1 << endl;
                str2.lower();
                cout << str2 << endl;
                break;

			default: 
                cont = 0;	
                break;
		}
	}
    return 0;
}

