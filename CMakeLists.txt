cmake_policy(SET CMP0048 NEW)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(ConfigurationDatabase VERSION 1.0.0)
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

# set the source directory
set(SOURCE_DIR source)

# set the include directories
include_directories(include)

# add all source files in source directory and its subdirectories
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

# create the executable
add_executable(db ${SOURCES})

# enable and create test executable enable_testing()
file(GLOB_RECURSE TEST_SOURCES test/*.cc ${SOURCE_DIR}/*.cpp)
list(FILTER TEST_SOURCES EXCLUDE REGEX "app.cpp$")
add_executable(dbtests ${TEST_SOURCES})
target_include_directories(dbtests PRIVATE include)
target_link_libraries(dbtests gtest_main)
add_test(NAME dbtests COMMAND dbtests)
