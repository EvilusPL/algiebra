#include <iostream>
#include "algiebra.h"

using namespace std;

int main() {
	int x;
	int** a;
	int** b;
	int** c;
	int** d;
	x = gcd(123,456);
	a = getAddModTable(5);
	b = getSubModTable(5);
	c = getMulModTable(5);
	d = getDivModTable(5);
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(b) = " << sizeof(a) << endl;
	cout << "sizeof(c) = " << sizeof(a) << endl;
	cout << "sizeof(d) = " << sizeof(a) << endl;
	cout << endl;
	cout << x << endl;
	cout << endl;
	printTable(a, 5);
	cout << endl;
	printTable(b, 5);
	cout << endl;
	printTable(c, 5);
	cout << endl;
	printTable(d, 5);
	cout << endl;
	removeTable(a, 5);
	removeTable(b, 5);
	removeTable(c, 5);
	removeTable(d, 5);
	return 0;
}
