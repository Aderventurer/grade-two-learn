#!/bin/bash

echo "Running Python Complex number"
python3 ./Python/complex_number.py

echo "Running C Complex number"
mkdir ./C/build
cd C/build
cmake ..
make
ctest

echo "Running Rust Complex number"
cd ../..
cd Rust
cd src
cargo  test
cd ..