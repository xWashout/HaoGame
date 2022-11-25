cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
project(unit_test)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()