cmake_minimum_required(VERSION 3.8)
project(S02P02)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Queue.cpp Entry.cpp PriorityQueue.cpp)
set(HEADER_FILES PriorityQueue.h Entry.h)
add_executable(S02P02 ${SOURCE_FILES})