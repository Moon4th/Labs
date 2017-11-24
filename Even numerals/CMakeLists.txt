cmake_minimum_required(VERSION 3.8)
project(even_numerals)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c)
add_executable(even_numerals ${SOURCE_FILES})