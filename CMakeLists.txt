cmake_minimum_required(VERSION 3.17)
project(8307_Ershov_OS_Lab3_p2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp -static")

add_executable(8307_Ershov_OS_Lab3_p2 main.cpp)

