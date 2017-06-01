// Algiebra - C++ library for mathematics
// (C) 2017 Jaroslaw Rauza. Licensed under BSD license

#include <cstdio>
#include <cstdlib>
#include "algiebra.h"

int getAbsolute(int a) {
	if (a<0)
	{
		a=a*(-1);
		return a;
	}
	return a;
}

int Euclid(int a, int b) {
	int x = 1;
	while ((a%b)!=0) {
		x=a%b;
		a=b;
		b=x;	
	}
	return x;
}

int gcd(int a, int b) {
	if (a<0) {
		a = getAbsolute(a);
	}
	if (b<0) {
		b = getAbsolute(b);
	}
	if (b == 0) {
		return getAbsolute(a);
	}
	if (a == 0) {
		return getAbsolute(b);
	}
	if (b%a == 0) {
		return getAbsolute(a);
	}
	if (a%b == 0) {
		return getAbsolute(b);
	}
	if (a>b) {
		int x=b;
		b=a;
		a=x;
	}
	return Euclid(a,b);
}

int** getAddModTable(int a) {
	if (a<0) {
		a = getAbsolute(a);
	}
	int** addTable = new int*[a];
	for (int i = 0; i < a; i++) {
		addTable[i] = new int[a];
		for (int j =  0; j < a; j++) {
			addTable[i][j] = (i+j)%a;
		}
	}
	return addTable;
}

int** getSubModTable(int a) {
	if (a<0) {
		a = getAbsolute(a);
	}
	int** subTable = new int*[a];
	for (int i = 0; i < a; i++) {
		subTable[i] = new int[a];
		for (int j =  0; j < a; j++) {
			subTable[i][j] = (i-j)%a;
		}
	}
	return subTable;
}

int** getMulModTable(int a) {
	if (a<0) {
		a = getAbsolute(a);
	}
	int** mulTable = new int*[a];
	for (int i = 0; i < a; i++) {
		mulTable[i] = new int[a];
		for (int j =  0; j < a; j++) {
			mulTable[i][j] = (i*j)%a;
		}
	}
	return mulTable;
}

int** getDivModTable(int a) {
	if (a<0) {
		a = getAbsolute(a);
	}
	int** divTable = new int*[a];
	for (int i = 0; i < a; i++) {
		divTable[i] = new int[a];
		for (int j =  0; j < a; j++) {
			if (j == 0) {
				divTable[i][j] = 0;
			}
			else {
				divTable[i][j] = (i/j)%a;
			}
		}
	}
	return divTable;
}

void printTable(int** t, int c) {
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			printf("%-8.1d", t[i][j]);
		}
		printf("\n");
	}	
}

void removeTable(int** t, int c) {
	for (int i = 0; i < c-1; i++) {
		delete[] t[i];
	}
	delete[] t;
}
