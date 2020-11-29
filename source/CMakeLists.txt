cmake_minimum_required(VERSION 3.0.0)
#project(main VERSION 0.1.0)


LINK_DIRECTORIES(lib)

include_directories(include)

aux_source_directory("./src" SRC_DIR)
list(REMOVE_ITEM SRC_DIR "main.cpp")

add_library(example ${SRC_DIR})

add_executable(main src/main.cpp)
target_link_libraries(main example)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")