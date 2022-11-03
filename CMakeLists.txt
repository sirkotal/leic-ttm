cmake_minimum_required(VERSION 3.23)
project(leic_ttm)

set(CMAKE_CXX_STANDARD 14)

include_directories(headers)

add_executable(leic_ttm
        src/main.cpp
        src/class_schedule.cpp
        headers/class_schedule.h
        src/interface.cpp
        headers/interface.h
        src/request.cpp
        headers/request.h
        src/slot.cpp
        headers/slot.h
        src/student.cpp
        headers/student.h
        src/ttm.cpp
        headers/ttm.h
        src/uc_class.cpp
        headers/uc_class.h)
