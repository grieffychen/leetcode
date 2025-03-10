cmake_minimum_required(VERSION 3.0)
set(Project_name lecode-dynamic-programing)
set (TARGET_NAME1 1043_partition_arr_max_sum)
set (TARGET_NAME2 53_maximum_subarray)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set (PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

project(${Project_name})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(${TARGET_NAME1} 1043_partition_arr_max_sum.c)
add_executable(${TARGET_NAME2} 53_maximum_subarray.c)
add_executable(292_nim_game 292_nim_game.c)
add_executable(392_is_subsequence 392_is_subsequence.c)
add_executable(300_longest_increasing_subsequence 300_longest_increasing_subsequence.c)

