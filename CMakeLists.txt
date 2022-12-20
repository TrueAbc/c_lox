cmake_minimum_required(VERSION 3.23)
project(c_lox C)

set(CMAKE_C_STANDARD 99)

include_directories(.)

add_library(libmem SHARED memory.c)
add_library(libchunk SHARED chunk.c value.c debug.c)


add_executable(c_lox main.c)

target_link_libraries(
        libchunk
        libmem
)

target_link_libraries(
        c_lox
        libchunk
)