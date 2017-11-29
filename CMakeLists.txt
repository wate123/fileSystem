cmake_minimum_required(VERSION 3.8)
project(fileSystem)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES softwaredisk.c filesystem.h  filesystem.c testfs0.c formatfs.c file.c)
add_executable(fileSystem ${SOURCE_FILES})