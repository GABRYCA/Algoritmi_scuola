cmake_minimum_required(VERSION 3.22)
project(Scacchi)

set(CMAKE_CXX_STANDARD 14)

add_executable(Scacchi main.cpp Scacchiera.cpp Scacchiera.h Pedone.cpp Pedone.h Cavallo.cpp Cavallo.h Alfiere.cpp Alfiere.h Torre.cpp Torre.h Donna.cpp Donna.h Re.cpp Re.h)
