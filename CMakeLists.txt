cmake_minimum_required(VERSION 3.17)
project(circulararray_circulararray)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(circulararray_circulararray
        circulararray.h
        main.cpp
        queue.h
        README.md
        stack.h
        tester.h)
