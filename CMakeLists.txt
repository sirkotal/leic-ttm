cmake_minimum_required(VERSION 3.23)
project(leic_ttm)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(leic_ttm
        classes/class.cpp
        classes/student.cpp
        classes/uc.cpp
        headers/class.h
        headers/student.h
        headers/uc.h
        src/main.cpp)
