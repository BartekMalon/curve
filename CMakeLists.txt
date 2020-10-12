cmake_minimum_required(VERSION 3.1)

project(game VERSION 1.0 LANGUAGES CXX)

find_package(SFML REQUIRED COMPONENTS graphics window system PATHS "${CMAKE_SOURCE_DIR}/lib/sfml/lib/cmake/SFML/")

file(GLOB SOURCES "src/*.cpp")
file(GLOB INCLUDES "include/*.hpp")

set(SFML_LIB_DIR "${CMAKE_SOURCE_DIR}/lib/sfml/lib")

add_executable(game ${SOURCES})
target_include_directories(game PRIVATE "include/" "lib/sfml/include")
target_link_libraries(game PRIVATE 
        "${SFML_LIB_DIR}/libsfml-graphics.so" 
        "${SFML_LIB_DIR}/libsfml-window.so" 
        "${SFML_LIB_DIR}/libsfml-system.so")



