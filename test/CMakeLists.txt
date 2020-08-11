cmake_minimum_required (VERSION 3.5)
project(TestCodeCoverage)

# add definitions
add_definitions(-fprofile-arcs -ftest-coverage)

# Include diretories
include_directories(/usr/include)
link_directories(/usr/lib)

# Set the compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE ON)

# Create OBJECT_DIR variable
set(OBJECT_DIR ${CMAKE_BINARY_DIR}/CMakeFiles/TestCodeCoverage.dir/src)
message("-- Object files will be output to: ${OBJECT_DIR}")

# Find required packages
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Set the sources
set(sources
    src/tMain.cpp
    src/CodeCoverageTest.cpp
    ../src/CodeCoverage.cpp
    )
# Set Include directories
include_directories(
                src/
                ../src/
                )

# Create the executable
add_executable(TestCodeCoverage ${sources})

# Set the sources
set(Factorial_sources
    src/tMain.cpp
    src/Factorial_Test.cpp
    ../src/Factorial.cpp
    )
# Set Include directories

# Create the FactorialTest executable
add_executable(FactorialTest ${Factorial_sources})

# Create the gcov target. Run coverage tests with 'make gcov'
add_custom_target(gcov
    COMMAND mkdir -p gcoverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
add_custom_command(TARGET gcov
    COMMAND echo "=================== GCOV ===================="
    COMMAND gcov -b ${CMAKE_SOURCE_DIR}/src/*.cpp -o ${OBJECT_DIR}
    COMMAND echo "-- Source diretorie: ${CMAKE_SOURCE_DIR}/src/"
    COMMAND echo "-- Coverage files have been output to ${CMAKE_BINARY_DIR}/gcoverage"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/gcoverage
    )
add_dependencies(gcov TestCodeCoverage)

# Create the lcov target. Run result tests with 'make lcov'
add_custom_target(lcov
    COMMAND mkdir -p lcoverage
    )
add_custom_command(TARGET lcov
    COMMAND echo "=================== LCOV ===================="
    COMMAND echo "-- Passing lcov tool under code coverage"
    COMMAND lcov --capture --directory ../ --output-file lcoverage/main_coverage.info
    COMMAND echo "-- Generating HTML output files"
    COMMAND genhtml lcoverage/main_coverage.info --output-directory lcoverage
    )

# Make sure to clean up the coverage folder
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES gcoverage)

# Create the gcov-clean target. This cleans the build as well as generated 
# .gcda and .gcno files.
add_custom_target(init
    COMMAND ${CMAKE_MAKE_PROGRAM} clean
    COMMAND rm -f ${OBJECT_DIR}/*.gcno
    COMMAND rm -f ${OBJECT_DIR}/*.gcda
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )

# Testing
enable_testing()

add_test(output_test ${CMAKE_CURRENT_BINARY_DIR}/TestCodeCoverage)

# link libraries to the TestCodeCoverage 
target_link_libraries(TestCodeCoverage gtest)
target_link_libraries(TestCodeCoverage gmock)
target_link_libraries(TestCodeCoverage pthread)
target_link_libraries(TestCodeCoverage -fprofile-arcs)
#target_link_libraries(TestCodeCoverage gcov)

# link libraries to the FactorialTest
target_link_libraries(FactorialTest gtest)
target_link_libraries(FactorialTest gmock)
target_link_libraries(FactorialTest pthread)