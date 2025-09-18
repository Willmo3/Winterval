cmake_minimum_required(VERSION 3.5)
project(winterval)

set(CMAKE_CXX_STANDARD 20)

add_library(winterval STATIC src/Winterval.cpp src/Winterval.h)

# Uncomment for sanity tests
# add_executable(win_test src/main.cpp)
# target_link_libraries(win_test winterval)
