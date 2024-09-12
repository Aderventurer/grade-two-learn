#!/bin/bash

echo "Running Python Hello World"
python3 ./Python/helloworld.py

echo "Running C Hello World"
mkdir ./C/build
gcc ./C/helloworld.c -o ./C/build/helloworld_c
./C/build/helloworld_c

echo "Running Rust Hello World"
cd Rust
cargo run
cd ..
