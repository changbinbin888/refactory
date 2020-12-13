cmake_minimum_required(VERSION 3.0.0)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(THIRD_PARTY_PATH ${CMAKE_CURRENT_SOURCE_DIR}/third_party)

link_directories(lib)
link_directories(${THIRD_PARTY_PATH}/mockcpp/lib
                 ${THIRD_PARTY_PATH}/gmock/lib
                 ${THIRD_PARTY_PATH}/gtest/lib
                 )

include_directories(include)
include_directories(${THIRD_PARTY_PATH}/gtest/include/
                    ${THIRD_PARTY_PATH}/gmock/include/
                    ${THIRD_PARTY_PATH}/mockcpp/include/
                    ${THIRD_PARTY_PATH}/mockcpp/3rdparty/
                    )

aux_source_directory("./src" SRC_DIR)

add_executable(test ${SRC_DIR})

TARGET_LINK_LIBRARIES(test gtest mockcpp example)

