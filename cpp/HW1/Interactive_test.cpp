
#include <iostream>
#include "X.h"

using namespace std;

int main()
{
	int cont = 1;			// trigger to stop loop	
	unsigned int option;
	X x;
	
	while (cont) {
		cout << "Choose option: " << endl;
		cout << "1: Insert  " << endl;
		cout << "2: Find    " << endl;
		cout << "3: Remove  " << endl;
		cout << "Any another number - stop " << endl;

		cin >>  option;
		switch (option) {
			case 1:
				// input param
				x.Insert();	break;
				// output of result
			case 2:
				x.Find();		break;
			case 3:
				x.Remove();	break;

			default: cont = 0;	break;
		}
	}

	return 0;
}

