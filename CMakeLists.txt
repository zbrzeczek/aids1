cmake_minimum_required(VERSION 3.27)
project(aids1)

set(CMAKE_CXX_STANDARD 17)

add_executable(aids1 main.cpp
        StosString.cpp
        StosString.h
        List.cpp
        List.h
        NodeString.h
        StosInt.cpp
        StosInt.h
        NodeInt.h
)
