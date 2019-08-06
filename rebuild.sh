#!/bin/bash



cd compiler
make clean
make
cd ../decompiler
make clean
make
cd ..
make clean
make
