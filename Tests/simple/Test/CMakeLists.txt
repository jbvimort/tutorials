cmake_minimum_required(VERSION 2.8)


include_directories( ${CMAKE_SOURCE_DIR} )
add_executable( TestWrite TestWrite.cxx)


add_test(NAME testMainWith COMMAND $<TARGET_FILE:write_test> FileName.txt inputText)
add_test(NAME TestMainWithoutArgs COMMAND $<TARGET_FILE:write_test> )
add_test(NAME TestOfTheOutputFile COMMAND $<TARGET_FILE:TestWrite>)
set_tests_properties(TestMainWithoutArgs PROPERTIES WILL_FAIL true)
