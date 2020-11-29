cmake_minimum_required(VERSION 3.0.0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

LINK_DIRECTORIES(lib)

include_directories(include)

aux_source_directory("./src" SRC_DIR)

message("build test.exe begin")
add_executable(test ${SRC_DIR})
#add_executable(test ${SRC_DIR})
TARGET_LINK_LIBRARIES(test gtest example)
message("build test.exe end")