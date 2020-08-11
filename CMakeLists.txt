cmake_minimum_required (VERSION 3.5)

project(UnitTestExample)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(Factorial
                src/Factorial.cpp
                src/main_factorial.cpp
)

include_directories(
                src/
)
