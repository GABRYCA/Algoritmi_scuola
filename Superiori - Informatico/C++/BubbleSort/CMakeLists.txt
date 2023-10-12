cmake_minimum_required(VERSION 3.20)
project(BubbleSort)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")


add_executable(BubbleSort main.cpp)
