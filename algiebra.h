// Algiebra - C++ library for mathematics
// (C) 2017 Jarosław Rauza. Licensed under BSD license

#ifndef _ALGIEBRA_H_
#define _ALGIEBRA_H_

int* Div(int n, int m);
int getAbsolute(int a);
int* ExtEuclid(int a, int b);
int Euclid(int a, int b);
int gcdExt(int a, int b);
int gcd(int a, int b);
int** getAddModTable(int a);
int** getSubModTable(int a);
int** getMulModTable(int a);
int** getDivModTable(int a);
void printTable(int** t, int c);
void removeTable(int** t, int c);
int printString(char* string);
int printChar(char chr);
int printInteger(int num);
void printNewLine();

#endif
