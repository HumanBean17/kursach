cmake_minimum_required(VERSION 3.13)
project(kursach)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(kursach
        additional_func.cpp
        header.h
        main.cpp
        )
