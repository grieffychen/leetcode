cmake_minimum_required(VERSION 3.0)
set(Project_name lecode-linklist)
set (TARGET_NAME1 1114_print_in_order)
set (TARGET_NAME2 1114_print_in_order_cond)
set (TARGET_NAME3 1115_print_foobar_alt)
set (TARGET_NAME4 1116_print_zero_even_odd)
set (TARGET_NAME5 1117_h2o)
set (TARGET_NAME6 1195_fizz_buzz)


set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set (PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
project(${Project_name})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(${TARGET_NAME1} 1114_print_in_order.c)
target_link_libraries(${TARGET_NAME1} pthread)

add_executable(${TARGET_NAME2} 1114_print_in_order_cond.c)
target_link_libraries(${TARGET_NAME2} pthread)
add_executable(${TARGET_NAME3} 1115_print_foobar_alt.c)
target_link_libraries(${TARGET_NAME3} pthread)

add_executable(${TARGET_NAME5} 1117_h2o.c)
target_link_libraries(${TARGET_NAME5} pthread)

add_executable(${TARGET_NAME6} 1195_fizz_buzz.c)
target_link_libraries(${TARGET_NAME6} pthread)