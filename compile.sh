#!/bin/sh
# Clean up the previous build
make clean
# Compile the source code
make
# Run the program
./bin/ooa_spice
