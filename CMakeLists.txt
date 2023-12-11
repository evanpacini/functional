cmake_minimum_required(VERSION 3.26)
project(functional LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)

include(CheckLibraryExists)

add_library(nil STATIC functional/src/list/helpers/nil.cpp)
target_include_directories(nil PRIVATE functional/include)

add_library(
  functional SHARED
  functional/src/functional_int.c functional/src/functional_float.c
  functional/src/functional_double.c
  functional/src/list/functional_list_double.c functional/src/error.c
        functional/src/object.c)
target_include_directories(functional PUBLIC functional/include)
target_link_libraries(functional PUBLIC nil)
check_library_exists(m floor "" LIBM)
if(LIBM)
  target_link_libraries(functional PRIVATE m)
endif()

add_executable(test main.c)
target_include_directories(test PRIVATE functional)
target_link_libraries(test PRIVATE functional)
