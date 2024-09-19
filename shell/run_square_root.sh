#!/bin/bash

echo "Running Python square root"
python3 ./Python/square_root.py

echo "Running C square root"
mkdir ./C/build
gcc ./C/square_root.c -o ./C/build/square_root_c
./C/build/square_root_c

echo "Running Rust square root"
cd Rust
cd src
cargo run --bin square_root
cd ..