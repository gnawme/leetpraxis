#!/bin/bash

for SRC in "$@"
do
g++ $SRC.cpp -std=c++1z -Werror -o $SRC
done