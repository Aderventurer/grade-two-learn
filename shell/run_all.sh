#!/bin/bash
pwd
echo "Running Python Hello World"
python3 ./Python/helloworld.py

pwd
echo "Running C Hello World"
gcc ./C/helloworld.c -o helloworld_c
./helloworld_c

pwd
echo "Running Rust Hello World"
cd Rust/src
cargo run
