#!/bin/bash

echo "Running Python Read An Integer"
python3 ./Python/read_an_integer.py

echo "Running C Read An Integer"
mkdir ./C/build
gcc ./C/read_an_integer.c -o ./C/build/read_an_integer_c
./C/build/read_an_integer_c

echo "Running Rust Read An Integer"
cd Rust
cd src
cargo run --bin read_an_integer
cd ..