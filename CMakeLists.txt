cmake_minimum_required(VERSION 3.26)
project(functional C)

set(CMAKE_C_STANDARD 23)

add_library(functional SHARED functional/src/functional_int.c
        functional/src/functional_float.c
        functional/src/functional_double.c
        functional/src/list/functional_list_double.c
        functional/src/error.c)
target_include_directories(functional PUBLIC functional/include)
target_link_libraries(functional PRIVATE m)

add_executable(test main.c)
target_include_directories(test PUBLIC functional)
target_link_libraries(test PRIVATE functional)
