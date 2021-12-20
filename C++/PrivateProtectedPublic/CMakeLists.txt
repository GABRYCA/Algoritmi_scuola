cmake_minimum_required(VERSION 3.21)
project(PrivateProtectedPublic)

set(CMAKE_CXX_STANDARD 14)

add_executable(PrivateProtectedPublic main.cpp Base.cpp Base.h FB1.cpp FB1.h FB2.cpp FB2.h)
