cmake_minimum_required(VERSION 3.0)
set(Project_name lecode-linklist)
set (TARGET_NAME1 682_baseball_game)


set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
set (PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
project(${Project_name})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(${TARGET_NAME1} 682_baseball_game.c)

