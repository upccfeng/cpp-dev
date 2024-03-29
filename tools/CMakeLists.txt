cmake_minimum_required(VERSION 3.0.0)

project(test_tools)

set(TOOLS_SRC_DIR ${CMAKE_SOURCE_DIR}/tools/src)
file(GLOB TOOLS_SRC_FILES ${TOOLS_SRC_DIR}/*.cpp)
file(GLOB TOOLS_INCLUDE_FILES ${TOOLS_INCLUDE_DIR}/*.hpp)

include_directories(${GOOGLE_TEST_INCLUDE_DIR} ${TOOLS_INCLUDE_DIR})
link_directories(${LIB_DIR})

add_library(tools ${TOOLS_SRC_FILES} ${TOOLS_INCLUDE_FILES})

add_executable(test_tools
    test_tools.cpp
)

if(MSVC)
target_link_libraries(test_tools tools gtest gmock gtest_main)
else()
target_link_libraries(test_tools tools gtest gmock gtest_main pthread)
endif()
