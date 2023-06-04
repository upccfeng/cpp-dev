cmake_minimum_required(VERSION 3.6)

project(test_processing)

file(GLOB SOLUTION_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

include_directories(${GOOGLE_TEST_INCLUDE_DIR} ${TOOLS_INCLUDE_DIR})
link_directories(${LIB_DIR})

add_executable(test_processing
    ${SOLUTION_FILES}
)

if(MSVC)
target_link_libraries(test_processing tools gtest gmock gtest_main)
else()
target_link_libraries(test_processing tools gtest gmock gtest_main pthread)
endif()