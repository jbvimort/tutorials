
# Add external data from midas
list(APPEND ExternalData_URL_TEMPLATES
"http://slicer.kitware.com/midas3/api/rest?method=midas.bitstream.download&checksum=%(hash)"
)

# Set Paths
set(TEMP_DIR ${erode_BINARY_DIR}/Testing/Temporary )
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data )

# Set data
set(result_r2 DATA{${SOURCE_DIR}/result_veau_r2.jpeg} )
set(result_r5 DATA{${SOURCE_DIR}/result_veau_r5.jpeg} )
set(Input DATA{${SOURCE_DIR}/veau.bmp} )
set( standardOutput ${TEMP_DIR}/standardOutput.jpeg )
set( RadiusValue2 ${TEMP_DIR}/RadiusValue2.jpeg )
set( RadiusValue5 ${TEMP_DIR}/RadiusValue5.jpeg )

# Add executables
include_directories( ${CMAKE_SOURCE_DIR} )
add_executable(ErodeFilterTest ErodeFilterTest.cxx)
target_link_libraries(ErodeFilterTest erodeLib)


# Test checking that the program cannot run without arguments
ExternalData_add_test(MY_DATA NAME OpenFileTest COMMAND $<TARGET_FILE:erode>)
set_tests_properties(OpenFileTest PROPERTIES WILL_FAIL true )

#Test checking that a wrong input will prevent the program from running
ExternalData_add_test(MY_DATA NAME ErodeFilterWrongInputFileName COMMAND $<TARGET_FILE:erode>
  WrongInput.jpeg
  ${standardOutput}
  -r 20
)
set_tests_properties( ErodeFilterWrongInputFileName PROPERTIES WILL_FAIL true )

# Tests checking that that the output image is what is expected
ExternalData_add_test(MY_DATA NAME ErodeFilterRadiusValue2 COMMAND $<TARGET_FILE:ErodeFilterTest>
  --compare
    ${result_r2}
    ${RadiusValue2}
  ModuleEntryPoint
    ${Input}
    -o ${RadiusValue2}
    -r 2
  )

ExternalData_add_test(MY_DATA NAME ErodeFilterRadiusValue5 COMMAND $<TARGET_FILE:ErodeFilterTest>
  --compare
    ${result_r5}
    ${RadiusValue5}
  ModuleEntryPoint
    ${Input}
    -o ${RadiusValue5}
    -r 5
  )

# Test for the command --help
add_test(NAME PrintHelp COMMAND $<TARGET_FILE:erode> --help)

ExternalData_Add_Target(MY_DATA)
