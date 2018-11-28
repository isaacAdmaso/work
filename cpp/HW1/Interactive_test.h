#ifndef X_H
#define X_H

#include <iostream>
using namespace std;

class X {
public:
	void Insert()	{ cout << "-----> X::Insert()" << endl;}
	void Find()		{ cout << "-----> X::Find()" << endl;}
	void Remove()	{ cout << "-----> X::Remove()" << endl;}
};

#endif
