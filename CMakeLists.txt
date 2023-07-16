cmake_minimum_required(VERSION 3.0)

project(good)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated-declarations")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/container)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/iterator)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/algorithm)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/other)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/adapter)

file(GLOB CONTAINER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/container/*.cpp")
file(GLOB ITERATOR_FILES "${CMAKE_CURRENT_SOURCE_DIR}/iterator/*.cpp")
file(GLOB ALGORITHM_FILES "${CMAKE_CURRENT_SOURCE_DIR}/algorithm/*.cpp")
file(GLOB OTHER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/other/*.cpp")
file(GLOB ADAPTER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/adapter/*.cpp")
file(GLOB SRC_FILES "./*.cpp")

add_executable(main ${SRC_FILES} ${CONTAINER_FILES} ${ITERATOR_FILES} ${ALGORITHM_FILES} ${OTHER_FILES} ${ADAPTER_FILES})

file(GLOB MEETING_FILES "app/meeting/*.cpp")
add_executable(meeting ${MEETING_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/app/memorycount)
file(GLOB MEMORY_COUNT_FILES "app/memorycount/*.cpp")
add_executable(memory_count ${MEMORY_COUNT_FILES})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/app/memory_check)
file(GLOB MEMORY_COUNT_FILES "app/memory_check/*.cpp")
add_executable(memory_check ${MEMORY_COUNT_FILES})