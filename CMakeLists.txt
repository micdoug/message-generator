cmake_minimum_required(VERSION 3.0)
project(message_generator)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.32 REQUIRED COMPONENTS program_options)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(Boost_USE_STATIC_LIBS TRUE)

set(SOURCE_FILES main.cpp UniformRandom.cpp UniformRandom.h MessageEvent.cpp MessageEvent.h)
add_executable(message_generator ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})