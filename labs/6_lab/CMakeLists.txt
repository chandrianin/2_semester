cmake_minimum_required(VERSION 3.24)
project(6_lab)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc/")
add_executable(6_lab main.cpp inc/logger.h)