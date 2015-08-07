cmake_minimum_required(VERSION 2.8)

if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

project(write_test)

#Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})

#Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

option(BUILD_TESTING "tests executable" ON)

add_executable(write_test main.cxx)

SEMMacroBuildCLI(
  NAME main
  EXECUTABLE_ONLY
  TARGET_LIBRARIES ${ITK_LIBRARIES}
  )
 


if (BUILD_TESTING)
    include(CTest)
    add_subdirectory(Test)
endif ()


