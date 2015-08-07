
include_directories( ${CMAKE_SOURCE_DIR} )
add_executable( TestAdd TestAdd.cxx ../add.cxx)

add_test(NAME TestAddFunction COMMAND $<TARGET_FILE:TestAdd>)
add_test(NAME testMainWithArgs COMMAND $<TARGET_FILE:add> test input output 1 2 3 )
add_test(NAME TestMain COMMAND $<TARGET_FILE:add> )
