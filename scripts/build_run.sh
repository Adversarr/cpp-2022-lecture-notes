#! /usr/bin/env sh
cmake --build build --target $1 && build/$1
