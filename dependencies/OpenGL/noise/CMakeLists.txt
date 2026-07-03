cmake_minimum_required(VERSION 3.8)
project(noise)

add_library(noise INTERFACE)
target_include_directories(noise INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include/")