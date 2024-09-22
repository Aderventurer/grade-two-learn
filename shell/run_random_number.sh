#!/bin/bash

echo "Running Python random number"
python3 ./Python/random_number.py 3

echo "Running C random number"
mkdir ./C/build
gcc ./C/random_number.c  -o ./C/build/random_number_c 
./C/build/random_number_c 3

echo "Running Rust random number"
cd Rust
cd src
cargo run --bin random_number 3
cd ..