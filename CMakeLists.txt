cmake_minimum_required(VERSION 3.27)
project(project_2)

set(CMAKE_CXX_STANDARD 17)

file(COPY src/structs/dataset DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(project_2 src/main.cpp
        src/structs/Graph.h
        src/structs/Airlines.cpp
        src/structs/Airlines.h
        src/structs/Airports.cpp
        src/structs/Airports.h
        src/structs/Flights.cpp
        src/structs/Flights.h
        src/Menu.cpp)
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "dconfig-tmp")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)