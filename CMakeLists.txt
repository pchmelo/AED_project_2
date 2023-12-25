cmake_minimum_required(VERSION 3.27)
project(project_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(project_2 main.cpp
        Graph.h
        Structs/Airlines.cpp
        Structs/Airports.cpp
        Structs/Flights.cpp)
