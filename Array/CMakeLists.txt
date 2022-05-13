set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
cmake_minimum_required(VERSION 3.8)

project(Array VERSION 1.0.0)

add_executable(output)

target_include_directories(output PUBLIC include/)
target_sources(output PUBLIC src/main.cpp)
