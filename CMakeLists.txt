cmake_minimum_required(VERSION 3.14)
project(Kursovaya)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Kursovaya
        v_push_back.cpp
        header.h
        main.cpp
        v_new.cpp add_elem.cpp)
