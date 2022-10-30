cmake_minimum_required(VERSION 3.23)
project(leic_ttm)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(leic_ttm
        src/class_schedule.cpp
        src/interface.cpp
        src/request.cpp
        src/slot.cpp
        src/student.cpp
        src/ttm.cpp
        src/uc_class.cpp
        headers/class_schedule.h
        headers/interface.h
        headers/request.h
        headers/slot.h
        headers/student.h
        headers/ttm.h
        headers/uc_class.h
        src/main.cpp)
