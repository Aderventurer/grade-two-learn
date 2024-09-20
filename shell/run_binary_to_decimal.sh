#!/bin/bash

echo "Rinning Python binary to decimal"
python3 ./Python/binary_to_decimal.py

echo "Running C binary to decimal"
mkdir ./C/build
gcc ./C/binary_to_decimal.c -o ./C/build/binary_to_decimal_c
./C/build/binary_to_decimal_c

echo "Running Rust binary to decimal"
cd Rust
cd src
cargo run --bin binary_to_decimal
cd ..