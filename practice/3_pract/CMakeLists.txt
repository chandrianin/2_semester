cmake_minimum_required(VERSION 3.24)
project(3_pract)

set(CMAKE_CXX_STANDARD 17)
include_directories("inc/")
add_executable(3_pract main.cpp src/kinematicSolver.cpp inc/kinematicSolver.h)
