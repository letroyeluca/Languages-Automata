cmake_minimum_required(VERSION 3.29)
project(Languages_Automata)

set(CMAKE_CXX_STANDARD 20)

add_executable(Languages_Automata main.cpp
        DFA.cpp
        DFA.h)
