cmake_minimum_required(VERSION 2.8)

if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

project(erode)

# Find SlicerExecutionModel
find_package(SlicerExecutionModel REQUIRED)
include(${SlicerExecutionModel_USE_FILE})

# Find ITK
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

set(erode erode.cxx)

SEMMacroBuildCLI(
  NAME erode
  EXECUTABLE_ONLY
  TARGET_LIBRARIES ${ITK_LIBRARIES}
  )
 
#add_executable(main erode.cxx)
#target_link_libraries(main ${ITK_LIBRARIES})

