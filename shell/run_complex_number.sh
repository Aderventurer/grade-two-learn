#!/bin/bash

echo "Running Python Complex number"
python3 ./Python/complex_number.py

echo "Running C Complex number"
mkdir ./C/build
gcc ./C/complex_number.c -o ./C/build/complex_number_c
./C/build/complex_number_c

echo "Running Rust Complex number"
cd Rust
cd src
cargo  test
cd ..