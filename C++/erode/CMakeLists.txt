cmake_minimum_required(VERSION 2.8)
 
project(erode)
 
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})
 
add_executable(main erode.cpp)
target_link_libraries(main ${ITK_LIBRARIES})