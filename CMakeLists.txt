project(ConfigurationDatabase)
cmake_minimum_required(VERSION 3.0)

# set the source directory
set(SOURCE_DIR src)

# set the include directories
include_directories(include)

# add all source files in source directory and its subdirectories
file(GLOB_RECURSE SOURCES ${SOURCE_DIR}/*.cpp)

# create the executable
add_executable(db app.cpp)
