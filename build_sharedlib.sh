#!/bin/sh
./buildlib.sh
g++ -shared -o libalgiebra.so libalgiebra.o -lm -fPIC
