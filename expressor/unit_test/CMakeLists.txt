cmake_minimum_required (VERSION 2.6) 

SET(gtest_BINARY_DIR ../../build_output/google_test)
SET(gtest_SOURCE_DIR ../../gtest-1.6.0)
SET(EXPRESSOR_SOURCE_DIR ../src)

include_directories(
  ${gtest_SOURCE_DIR}
  ${gtest_SOURCE_DIR}/include)

# Where Google Test's libraries can be found.
link_directories(${gtest_BINARY_DIR})

include_directories (${EXPRESSOR_SOURCE_DIR}) 

LINK_LIBRARIES(gtest)

add_executable (unitTest unit_test.cpp) 
