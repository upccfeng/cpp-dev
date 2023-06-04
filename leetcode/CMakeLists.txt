cmake_minimum_required(VERSION 3.6)

project(test_problems)

file(GLOB SRC_DIR ${PROJECT_SOURCE_DIR}/src)
file(GLOB SRC_FILES ${SRC_DIR}/*.cpp)

include_directories(${TOOLS_INCLUDE_DIR})
link_directories(${LIB_DIR})
add_library(problems ${SRC_FILES})

include_directories(${GOOGLE_TEST_INCLUDE_DIR} ${SRC_DIR})
add_executable(test_problems
    ${PROJECT_SOURCE_DIR}/test_problems.cpp
)

if(MSVC)
target_link_libraries(test_problems tools gtest gmock gtest_main)
add_definitions(/bigobj)
else()
target_link_libraries(test_problems tools gtest gmock gtest_main pthread)
endif()