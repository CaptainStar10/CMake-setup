cmake_minimum_required(VERSION 3.8)
project(Application)

add_library(Application INTERFACE)
target_include_directories(Application INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/")