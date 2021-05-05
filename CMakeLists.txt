cmake_minimum_required(VERSION 3.19)
project(avxsse_temp)

set(CMAKE_CXX_STANDARD 14)


add_executable(avxsse_temp main.cpp test.cpp)
target_compile_options(avxsse_temp PRIVATE -mavx)