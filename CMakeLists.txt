# Since 3.6 version,user can use VS_STARTUP_PROJECT to specify startup project.
cmake_minimum_required(VERSION 3.6)

project(test_cppdev)

add_definitions(-std=c++17)
add_definitions(-g -O0)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

enable_testing()

set(BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(GOOGLE_TEST_INSTALL_DIR ${BUILD_DIR}/install/googletest)
set(GOOGLE_TEST_INCLUDE_DIR ${GOOGLE_TEST_INSTALL_DIR}/include)
set(LIB_DIR ${GOOGLE_TEST_INSTALL_DIR}/lib)

set(TOOLS_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/tools/include)

if(MSVC)
    # for default MSVC env, it uses MDd
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

    add_subdirectory(${BUILD_DIR}/third_party_source/googletest third_party_build)
elseif(APPLE)
    add_subdirectory(${BUILD_DIR}/third_party_source/googletest third_party_build)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/processing)
add_subdirectory(${CMAKE_SOURCE_DIR}/leetcode)
add_subdirectory(${CMAKE_SOURCE_DIR}/tools)

if(NOT MSVC)
    include_directories(${GOOGLE_TEST_INCLUDE_DIR})
    include_directories(${TOOLS_INCLUDE_DIR})
    link_directories(${LIB_DIR})
endif()

if(MSVC)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_processing)

    add_test(NAME test_tools COMMAND test_tools)
    add_test(NAME test_processing COMMAND test_processing)
    add_test(NAME test_all COMMAND test_all)
endif()