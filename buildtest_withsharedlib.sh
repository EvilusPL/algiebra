#!/bin/sh
./build_sharedlib.sh
g++ test.cpp libalgiebra.so -o test2
