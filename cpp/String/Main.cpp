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
    char inString[MAX],testSub[MAX],*testFail;
    size_t idx,startCpy,lenCpy;
    String_t str1, str2;
    
	while (cont) 
    {
        cout << endl;

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
		cout << "14: set fag to true " << endl;
		cout << "15: set fag to  false" << endl;
		cout << "Any another number - stop " << endl;
        cout << endl;

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
                testFail = str2;
                strcpy(testSub,str2);
                cout  << "test cast String_t to: "<< str2 <<endl<<"char[]:" << testSub << endl <<"char*:"<< testFail << endl;
                cout  << "test substring  cast "<< endl;
                cout  <<"enter start and length of substring:"<< endl;
                cin   >> startCpy >> lenCpy;
                str1 = str2(startCpy,lenCpy);
                strcpy(testSub ,(char*)str2(startCpy,lenCpy));
                testFail = str1;

                cout <<" :*test char**"<<endl<< testFail << endl << testSub << endl ;
                cout  <<" :*test Class"<<endl<< str1  << endl;
                cout << str2;

                break;
			case 2:
                cout << str1<< endl;
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
                cout << "is 1st string contains 2nd string: "<<(char*)((str1.contains(inString))?"yes":"no") << endl;
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

            case 14:
                cout << "case flage - set to case sensitive";
                String_t::setFlag(true);
                break;
            
            case 15:
                cout << "case flage - set to case insensitive";
                String_t::setFlag(false);
                break;
			default: 
                cont = 0;	
                break;
		}
	}
    return 0;
}

