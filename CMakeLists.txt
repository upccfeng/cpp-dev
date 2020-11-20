cmake_minimum_required(VERSION 3.0.0)

project(test_processing)

add_definitions(-std=c++14)
add_definitions(-g -O0)

set(PROCESSING_DIR ${CMAKE_SOURCE_DIR}/processing)
set(BUILD_DIR ${CMAKE_SOURCE_DIR}/build)
set(GOOGLE_TEST_INSTALL_DIR ${BUILD_DIR}/install/googletest)
set(GOOGLE_TEST_INCLUDE_DIR ${GOOGLE_TEST_INSTALL_DIR}/include)
set(LIB_DIR ${GOOGLE_TEST_INSTALL_DIR}/lib)
set(TOOLS_SRC_DIR ${CMAKE_SOURCE_DIR}/tools/src)
set(TOOLS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/tools/include)

add_subdirectory(${CMAKE_SOURCE_DIR}/tools)
add_subdirectory(${CMAKE_SOURCE_DIR}/leetcode)

include_directories(${GOOGLE_TEST_INCLUDE_DIR})
link_directories(${LIB_DIR})

add_executable(test_processing
    test_processing.cpp
    ${PROCESSING_DIR}/solution.cpp
)

target_link_libraries(test_processing gtest gmock gtest_main pthread)