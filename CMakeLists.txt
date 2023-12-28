cmake_minimum_required(VERSION 3.27)
project(project_2)

set(CMAKE_CXX_STANDARD 17)

file(COPY src/structs/dataset DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(project_2 src/main.cpp
        src/structs/Graph.h
        src/structs/Airlines.cpp
        src/structs/Airports.cpp
        src/structs/Flights.cpp
        src/Menu.cpp)
