cmake_minimum_required(VERSION 3.1)

project(oving1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(main_a main_a.cpp)
add_executable(main_b main_b.cpp)

