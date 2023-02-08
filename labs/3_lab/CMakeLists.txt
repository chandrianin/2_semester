cmake_minimum_required(VERSION 3.24)
project(3_lab)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc/")

add_executable(3_lab main.cpp src/complex.cpp inc/complex.h)
