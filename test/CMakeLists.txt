cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(bspec_test)

get_filename_component(BSPEC_DIR "${CMAKE_CURRENT_SOURCE_DIR}" PATH)
message(STATUS "BSPEC_DIR: " ${BSPEC_DIR})

include(${BSPEC_DIR}/shared.cmake)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Threads)

set(TEST_DIR ${BSPEC_DIR}/test)

set(TEST_SOURCES
  ${TEST_DIR}/driver.cpp
  ${TEST_DIR}/spec.cpp
)

include_directories(${BSPEC_DIR}/include)

add_executable(bspec_test ${TEST_SOURCES})
target_link_libraries(bspec_test ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

# configure unit tests via CTest
enable_testing()
add_test(NAME RunTests COMMAND bspec_test)
