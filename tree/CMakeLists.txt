cmake_minimum_required(VERSION 3.10)
set(projectname "tree")
set (CMAKE_C_STANDARD)
set(EXECUTABLE_OUTPUT_PATH "../bin")
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set (PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
project(projectname)
add_executable(897_inc_order_bt 897_inc_order_bt.c)
add_executable(589_n_array_tree_preorder 589_n_array_tree_preorder.c)
add_executable(590_n_array_tree_postorder 590_n_array_tree_postorder.c)
