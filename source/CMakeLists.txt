cmake_minimum_required(VERSION 3.0.0)
#project(main VERSION 0.1.0)

LINK_DIRECTORIES(lib)

add_executable(main src/main.cpp)

include_directories(include)
