cmake_minimum_required(VERSION 3.0.0)
#project(test VERSION 0.1.0)

LINK_DIRECTORIES(lib)

include_directories(include)

aux_source_directory("./src" SRC_DIR)

add_executable(test ${SRC_DIR})
TARGET_LINK_LIBRARIES(test gtest exmaple)

