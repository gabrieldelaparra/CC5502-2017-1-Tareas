cmake_minimum_required(VERSION 3.7)
project(Tarea1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Point.h Vector.h Segment.h Polygon.h)
add_executable(Tarea1 ${SOURCE_FILES})