cmake_minimum_required(VERSION 3.5)
project(BruteForceFever)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp ParserClass.cpp ParserClass.h)
add_executable(BruteForceFever ${SOURCE_FILES})