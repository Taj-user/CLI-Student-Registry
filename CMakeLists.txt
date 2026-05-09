cmake_minimum_required(VERSION 4.3)
project(StudentRegistry)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(registry src/main.c src/menu.c src/registry.c src/student.c src/fileio.c)
