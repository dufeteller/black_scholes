cmake_minimum_required(VERSION 3.31)
project(black_scholes)

set(CMAKE_CXX_STANDARD 17)

add_library(black_scholes STATIC library.cpp)
