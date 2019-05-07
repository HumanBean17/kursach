cmake_minimum_required(VERSION 3.13)
project(kursach)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(kursach
        add_elem.cpp
        header.h
        main.cpp
        v_new.cpp
        v_push_back.cpp)
