cmake_minimum_required(VERSION 3.7)

project(Crypto)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(TOP_LEVEL_PATH ${CMAKE_SOURCE_DIR}/src)

add_subdirectory(${TOP_LEVEL_PATH})
