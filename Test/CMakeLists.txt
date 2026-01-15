cmake_minimum_required(VERSION 3.5.0)

#set(CXX_STANDARD 11)

add_subdirectory(./lib/googletest-main)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES Run_All_Tests.cpp)
add_executable(w_test ${TEST_SOURCE_FILES})
target_link_libraries(w_test gtest gtest_main ${CMAKE_PROJECT_NAME}_lib)