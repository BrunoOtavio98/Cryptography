cmake_minimum_required(VERSION 3.21)

project(Crypto)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(TOP_LEVEL_PATH ${CMAKE_SOURCE_DIR}/src)
SET(LIB_LEVEL_PATH ${CMAKE_SOURCE_DIR}/libs)

add_subdirectory(${TOP_LEVEL_PATH})
add_subdirectory(${LIB_LEVEL_PATH}/cryptopp-cmake)

