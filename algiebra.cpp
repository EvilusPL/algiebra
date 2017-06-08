// Algiebra - C++ library for mathematics
// (C) 2017 Jaroslaw Rauza. Licensed under BSD license

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "algiebra.h"

int* Div(int n, int m) {
	int q,r;
	static int out[2];
	
	q=0;
	r=n;
	while(r>=m) {
		q=q+1;
		r=r-m;
	}
	out[0]=q;
	out[1]=r;
	return out;
}

int getAbsolute(int a) {
	if (a<0)
	{
		a=a*(-1);
		return a;
	}
	return a;
}

int* ExtEuclid(int a, int b) {
	int a0 = a, b0 = b;
	int p = 1, q = 0;
	int r = 0, s = 1;
	int c, quot, r_tmp, s_tmp;
	static int out[3];
	while (b != 0) {
		c = Div(a,b)[1];
		quot = Div(a,b)[0];
		a = b;
		b = c;
		r_tmp = r;
		s_tmp = s;
		r = p - quot * r;
		s = q - quot * s;
		p = r_tmp;
		q = s_tmp;
	}
	out[0]=p*a0+q*b0;
	out[1]=p;
	out[2]=q;
	return out;
}

int Euclid(int a, int b) {
	int x = 1;
	while ((Div(a,b)[1])!=0) {
		x=Div(a,b)[1];
		a=b;
		b=x;	
	}
	return x;
}

int gcdExt(int a, int b) {
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
	return ExtEuclid(a,b)[0];
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
			addTable[i][j] = Div(i+j, a)[1];
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
			subTable[i][j] = Div(i-j, a)[1];
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
			mulTable[i][j] = Div(i*j, a)[1];
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
				divTable[i][j] = Div(Div(i, j)[0], a)[1];
			}
		}
	}
	return divTable;
}

void printTable(int** t, int c) {
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			printInteger(t[i][j]);
			printString("        ");
		}
		printNewLine();
	}	
}

void removeTable(int** t, int c) {
	for (int i = 0; i < c-1; i++) {
		delete[] t[i];
	}
	delete[] t;
}

int printString(char* string) {
	printf("%s", string);
	return strlen(string);
}

int printChar(char chr) {
	printf("%c", chr);
	return (int)chr;
}

int printInteger(int num) {
	printf("%d", num);
	return num;
}

void printNewLine() {
	printf("\n");
}
