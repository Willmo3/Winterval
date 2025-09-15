cmake_minimum_required(VERSION 4.0)
project(winterval)

set(CMAKE_CXX_STANDARD 20)

add_library(winterval STATIC src/Winterval.cpp src/Winterval.h)

add_executable(win_test src/main.cpp winterval)