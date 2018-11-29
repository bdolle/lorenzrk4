cmake_minimum_required(VERSION 3.9)
project(RungeClassTest)

set(CMAKE_CXX_STANDARD 11)

add_executable(RungeClassTest main.cpp ray.cpp ray.h Coords.cpp Coords.h)