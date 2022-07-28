cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

project(StackApplication)

add_library(stack STATIC stack.h)
set_target_properties(stack PROPERTIES LINKER_LANGUAGE CXX)
add_executable(sa application.cpp)
