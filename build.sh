#!/bin/sh
set -e
clang++ -std=c++17 -Wall -Wextra \
    -o toychain src/*.cpp -lcrypto
echo "OK: ./toychain"
