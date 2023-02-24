cmake_minimum_required(VERSION 3.24)
project(4_lab)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc/")
add_executable(4_lab main.cpp src/matrix.cpp inc/matrix.h)
