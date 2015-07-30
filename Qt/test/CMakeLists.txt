# This is the root ITK CMakeList file: 
cmake_minimum_required(VERSION 2.6)

# This project is designed to be built outside the Insight source tree.
PROJECT(GUI)

## Find Libraries ##
# find package(libraryName /QUIET /REQUIRED) generate variables containing the library way
# include(${VariableName}) 

# Find ITK (requires a version of ITK containing ITKVTKGlue)
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

# Find VTK
find_package(VTK 6.2.0 REQUIRED NO_MODULE)
include(${VTK_USE_FILE})

# Find QT
find_package(Qt4 REQUIRED)
INCLUDE (${QT_USE_FILE})

# MotherWindow.h generation
QT4_WRAP_UI(UI_SOURCES mainwindow.ui)

# Meta Object Compiler
QT4_WRAP_CPP(MOC_SOURCES mainwindow.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

# window_SOURCES and window_HEADERS
SET(Window_SOURCES mainwindow.cpp main.cpp)
SET(Window_HEADERS mainwindow.h)

# EXECUTABLE
ADD_EXECUTABLE(GUI ${MOC_SOURCES} ${UI_SOURCES} ${Window_SOURCES} ${Window_HEADERS})

TARGET_LINK_LIBRARIES(GUI  ${QT_LIBRARIES} ${ITK_LIBRARIES} ${VTK_LIBRARIES} ${ItkVtkGlue_LIBRARIES} QVTK)
