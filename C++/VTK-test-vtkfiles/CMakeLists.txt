cmake_minimum_required(VERSION 2.8)
 
project(main)
 
find_package(VTK REQUIRED)
include(${VTK_USE_FILE})
 
add_executable(main VTK-test.cpp)
target_link_libraries(main ${VTK_LIBRARIES})