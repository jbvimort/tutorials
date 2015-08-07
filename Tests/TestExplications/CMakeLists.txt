project(add)

add_executable( add main.cxx add.cxx)


option(BUILD_TESTING "tests" ON)
if( BUILD_TESTING )
  include(CTest)
  add_subdirectory( Testing )
endif()
