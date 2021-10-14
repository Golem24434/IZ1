cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 99)

add_library(lib STATIC function.c)

add_executable(output ./DZ1.c)

target_link_libraries(output lib)