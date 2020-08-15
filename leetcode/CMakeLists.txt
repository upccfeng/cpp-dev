cmake_minimum_required(VERSION 3.0.0)

project(test_all)

file(GLOB SOLUTION_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

include_directories(${INCLUDE_DIR} ${TOOLS_INCLUDE_DIR})
link_directories(${LIB_DIR})

add_executable(test_all
    test_all.cpp
    ${SOLUTION_FILES}
)

target_link_libraries(test_all tools gtest gtest_main pthread)