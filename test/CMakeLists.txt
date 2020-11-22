cmake_minimum_required(VERSION 3.0.0)
#project(test VERSION 0.1.0)

LINK_DIRECTORIES(lib)

add_executable(test src/test.cpp ../source/src/main.cpp)

include_directories(include)

TARGET_LINK_LIBRARIES(test gtest)

