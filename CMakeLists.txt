cmake_minimum_required(VERSION 4.2)
project(ds_assignment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ds_assignment2
        EmergencyRoomController.cpp
        EmergencyRoomController.h
        Heap.h
        main.cpp
        Patient.h)
