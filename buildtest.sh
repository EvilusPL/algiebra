#!/bin/sh
./buildlib.sh
g++ test.cpp libalgiebra.o -o test
