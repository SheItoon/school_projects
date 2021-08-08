cmake_minimum_required(VERSION 3.17)
project(B-YEP-400-LYN-4-1-indiestudio-guillaume.soisson CXX)

set(CMAKE_CXX_STANDARD 20)
set(PROJECT bomberman)
set(C_EXTENTION cpp)
set(H_EXTENTION hpp)

file(GLOB_RECURSE SCRIPT_FILE game/sources/*.${C_EXTENTION})
file(GLOB_RECURSE SCRIPT_FILE raylib_module/sources/*.${C_EXTENTION} ${SCRIPT_FILE})
file(GLOB_RECURSE SCRIPT_FILE lib/engine/sources/*.${C_EXTENTION} ${SCRIPT_FILE})
file(GLOB_RECURSE SCRIPT_FILE lib/json_parser/sources/*.${C_EXTENTION} ${SCRIPT_FILE})

file(GLOB_RECURSE HEADER_FILE game/includes/*.${H_EXTENTION})
file(GLOB_RECURSE HEADER_FILE raylib_module/includes/*.${H_EXTENTION} ${HEADER_FILE})
file(GLOB_RECURSE HEADER_FILE lib/engine/*.${H_EXTENTION} ${HEADER_FILE})
file(GLOB_RECURSE HEADER_FILE lib/SW/*.${H_EXTENTION} ${HEADER_FILE})
file(GLOB_RECURSE HEADER_FILE lib/json_parser/includes/*.${H_EXTENTION} ${HEADER_FILE})

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION ${CMAKE_BINARY_DIR})

file(GLOB_RECURSE INLINE_FILE raylib_module/includes/*.inl ${INLINE_FILE})

set(SOURCES ${SCRIPT_FILE} ${HEADER_FILE} ${INLINE_FILE})
add_executable(${PROJECT} ${SOURCES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
find_package(raylib REQUIRED)
target_link_libraries(${PROJECT} raylib)
if (UNIX)
    target_compile_options(${PROJECT} PRIVATE -g3)
endif (UNIX)
#add_library(ShipWreckEngine SHARED IMPORTED)
#set_target_properties(ShipWreckEngine PROPERTIES
#        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/libShipWreckEngine.so")

#add_library(jsnp STATIC IMPORTED)
#set_target_properties(jsnp PROPERTIES
#        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/lib/json_parser/libjsnp.a")

target_include_directories(${PROJECT}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/game/includes/
        ${CMAKE_SOURCE_DIR}/raylib_module/includes/
        ${CMAKE_SOURCE_DIR}/lib/json_parser/
        ${CMAKE_SOURCE_DIR}/lib/engine/includes/
        ${CMAKE_SOURCE_DIR}/lib/json_parser/includes/
        ${CMAKE_SOURCE_DIR}/lib/)

#target_link_libraries(${PROJECT} jsnp)