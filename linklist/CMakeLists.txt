cmake_minimum_required(VERSION 3.0)
set(Project_name lecode-linklist)
set (TARGET_NAME1 1290_convert_bin_in_linklist)
set (TARGET_NAME2 876_mid_linklist)
set (TARGET_NAME3 206_rev_linklist)
set (TARGET_NAME4 705_hash_set_linklist)
set (TARGET_NAME5 706_hashmap)
set (TARGET_NAME6 21_merge_sort_list)
set (TARGET_NAME7 160_intersection_node)
set (TARGET_NAME8 83_rm_dplist)
set (TARGET_NAME9 234_plaindrome_llist)
set (TARGET_NAME10 141_cycle_llist)
set (TARGET_NAME11 1699_merge_2linklist)
set (TARGET_NAME12 2130_max_twin_sum)
set (TARGET_NAME13 test_2pointer)
set (TARGET_NAME14 1472_browser_history)
set (TARGET_NAME15 2236_spiral_matrix)
set (TARGET_NAME16 2487_rm_node)
set (TARGET_NAME17 2_add_2nums)
set (TARGET_NAME18 19_rm_nth_from_end)
set (TARGET_NAME19 24_swap_nodes_parirs)
set (TARGET_NAME20 61_roate_list)
set (TARGET_NAME21 82_rm_duplicate_list)
set (TARGET_NAME22 86_partition_list)
set (TARGET_NAME23 92_rev_linklist2)


set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set (PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
project(${Project_name})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(${TARGET_NAME1} 1290_convert_bin_in_linklist.c)
add_executable(${TARGET_NAME2} 876_mid_linklist.c)
add_executable(${TARGET_NAME3} 206_rev_linklist.c)
add_executable(${TARGET_NAME5} 706_hashmap.c)
add_executable(${TARGET_NAME6} 21_merge_sort_list.c)
add_executable(${TARGET_NAME7} 160_intersection_node.c)
add_executable(${TARGET_NAME8} 83_rm_dplist.c)
add_executable(${TARGET_NAME9} 234_plaindrome_llist.c)
add_executable(${TARGET_NAME10} 141_cycle_llist.c)
add_executable(${TARGET_NAME11} 1699_merge_2linklist.c)
add_executable(${TARGET_NAME12} 2130_max_twin_sum.c)
add_executable(${TARGET_NAME13} test_2pointer.c)
add_executable(${TARGET_NAME14} 1472_browser_history.c)
add_executable(${TARGET_NAME15} 2236_spiral_matrix.c)
add_executable(${TARGET_NAME16} 2487_rm_node.c)
add_executable(${TARGET_NAME17} 2_add_2nums.c)
target_link_libraries(${TARGET_NAME17}  m)
add_executable(${TARGET_NAME18} 19_rm_nth_from_end.c)
add_executable(${TARGET_NAME19} 24_swap_nodes_parirs.c)
add_executable(${TARGET_NAME20} 61_roate_list.c)
add_executable(${TARGET_NAME21} 82_rm_duplicate_list.c)
add_executable(${TARGET_NAME22} 86_partition_list.c)
add_executable(${TARGET_NAME23} 92_rev_linklist2.c)
