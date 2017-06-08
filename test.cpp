#include <iostream>
#include "algiebra.h"

using namespace std;

int main() {
	int x;
	int y;
	int** a;
	int** b;
	int** c;
	int** d;
	cout << "Calculating gcd(123,456)... " << endl;
	x = gcd(123,456);
	cout << "Calculating gcdExt(123,456)... " << endl;
	y = gcdExt(123,456);
	cout << "Calculating getAddModTable(5)... " << endl;
	a = getAddModTable(5);
	cout << "Calculating getSubModTable(5)... " << endl;
	b = getSubModTable(5);
	cout << "Calculating getMulModTable(5)... " << endl;
	c = getMulModTable(5);
	cout << "Calculating getDivModTable(5)... " << endl;
	d = getDivModTable(5);
	cout << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "sizeof(y) = " << sizeof(y) << endl;
	cout << "sizeof(a) = " << sizeof(a) << endl;
	cout << "sizeof(b) = " << sizeof(a) << endl;
	cout << "sizeof(c) = " << sizeof(a) << endl;
	cout << "sizeof(d) = " << sizeof(a) << endl;
	cout << endl;
	cout << x << endl;
	cout << endl;
	cout << y << endl;
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
