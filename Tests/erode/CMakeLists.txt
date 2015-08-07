cmake_minimum_required(VERSION 2.8)

if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

project(erode)

# Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})
include(${GenerateCLP_USE_FILE})

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

option(BUILD_TESTING "tests executable" ON)

set(erode erode.cxx)

SEMMacroBuildCLI(
  NAME erode
  EXECUTABLE_ONLY
  TARGET_LIBRARIES ${ITK_LIBRARIES}
  )
 
if (BUILD_TESTING)
    include(ExternalData)
    include(CTest)
    add_subdirectory(Testing)
endif ()


