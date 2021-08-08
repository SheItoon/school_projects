cmake_minimum_required(VERSION 3.17)
project(ShipWreckEngine VERSION 0.1.0 LANGUAGES CXX)

set(PROJECT_NAME ShipWreckEngine)

set(CMAKE_CONFIGURATION_TYPES "DEBUG;INTERFACE;UNITEST" CACHE STRING "" FORCE)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SCRIPT_FILE ./sources/*.cpp)
file(GLOB_RECURSE HEADER_FILE ./includes/*.hpp)
set(SOURCES ${SCRIPT_FILE} ${HEADER_FILE})

add_library(ShipWreckEngine STATIC IMPORTED)
set_target_properties(ShipWreckEngine PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../json_parser/libjsnp.a")

target_include_directories(${PROJECT_NAME}
        PUBLIC
            ./../
        PRIVATE
            ./includes/)