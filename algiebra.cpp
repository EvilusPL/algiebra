// Algiebra - C++ library for mathematics
// (C) 2017 Jaroslaw Rauza. Licensed under BSD license

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
