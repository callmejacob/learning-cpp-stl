cmake_minimum_required(VERSION 3.0)

project(good)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC_FILES "./*.cpp")

add_executable(main ${SRC_FILES})
