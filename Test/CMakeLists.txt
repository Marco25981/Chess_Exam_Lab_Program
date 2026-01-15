cmake_minimum_required(VERSION 3.5.0)

# 1. Definisco dove si trova GoogleTest
set(GTEST_DIR "${CMAKE_SOURCE_DIR}/Test/lib/googletest-main") 

# 2. Includo gli header files (.h)
include_directories("${GTEST_DIR}/include")
include_directories("${GTEST_DIR}")

# 3. Aggiungiamo la subdirectory per compilare gtest (se non è già fatto nel main)
# La parte "binary_dir" (il secondo argomento) serve a tenere pulita la build
add_subdirectory("${GTEST_DIR}" "${CMAKE_BINARY_DIR}/googletest-build")

set(TEST_SOURCE_FILES Run_All_Tests.cpp)

add_executable(w_test ${TEST_SOURCE_FILES})

# 4. Linkaggio
target_link_libraries(w_test 
    PRIVATE 
    gtest 
    gtest_main 
    w_lib 
    ${wxWidgets_LIBRARIES}
)