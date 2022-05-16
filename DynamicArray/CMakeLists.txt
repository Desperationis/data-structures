set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 11)

project(DynamicArray VERSION 1.0.0)

add_executable(DynamicArray)

# Google Test
include(GoogleTest)
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

target_include_directories(DynamicArray PUBLIC include/)
target_sources(DynamicArray PUBLIC src/main.cpp)
target_link_libraries(DynamicArray gtest_main)

gtest_discover_tests(DynamicArray)
