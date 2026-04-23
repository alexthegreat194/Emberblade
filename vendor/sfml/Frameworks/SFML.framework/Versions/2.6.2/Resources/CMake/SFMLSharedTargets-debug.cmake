#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "sfml-system" for configuration "Debug"
set_property(TARGET sfml-system APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-system PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./sfml-system.framework/Versions/2.6.2/sfml-system"
  IMPORTED_SONAME_DEBUG "@rpath/sfml-system.framework/Versions/2.6.2/sfml-system"
  )

list(APPEND _cmake_import_check_targets sfml-system )
list(APPEND _cmake_import_check_files_for_sfml-system "${_IMPORT_PREFIX}/./sfml-system.framework/Versions/2.6.2/sfml-system" )

# Import target "sfml-window" for configuration "Debug"
set_property(TARGET sfml-window APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-window PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./sfml-window.framework/Versions/2.6.2/sfml-window"
  IMPORTED_SONAME_DEBUG "@rpath/sfml-window.framework/Versions/2.6.2/sfml-window"
  )

list(APPEND _cmake_import_check_targets sfml-window )
list(APPEND _cmake_import_check_files_for_sfml-window "${_IMPORT_PREFIX}/./sfml-window.framework/Versions/2.6.2/sfml-window" )

# Import target "sfml-network" for configuration "Debug"
set_property(TARGET sfml-network APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-network PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./sfml-network.framework/Versions/2.6.2/sfml-network"
  IMPORTED_SONAME_DEBUG "@rpath/sfml-network.framework/Versions/2.6.2/sfml-network"
  )

list(APPEND _cmake_import_check_targets sfml-network )
list(APPEND _cmake_import_check_files_for_sfml-network "${_IMPORT_PREFIX}/./sfml-network.framework/Versions/2.6.2/sfml-network" )

# Import target "sfml-graphics" for configuration "Debug"
set_property(TARGET sfml-graphics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-graphics PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./sfml-graphics.framework/Versions/2.6.2/sfml-graphics"
  IMPORTED_SONAME_DEBUG "@rpath/sfml-graphics.framework/Versions/2.6.2/sfml-graphics"
  )

list(APPEND _cmake_import_check_targets sfml-graphics )
list(APPEND _cmake_import_check_files_for_sfml-graphics "${_IMPORT_PREFIX}/./sfml-graphics.framework/Versions/2.6.2/sfml-graphics" )

# Import target "sfml-audio" for configuration "Debug"
set_property(TARGET sfml-audio APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(sfml-audio PROPERTIES
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "OpenAL::OpenAL"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/./sfml-audio.framework/Versions/2.6.2/sfml-audio"
  IMPORTED_SONAME_DEBUG "@rpath/sfml-audio.framework/Versions/2.6.2/sfml-audio"
  )

list(APPEND _cmake_import_check_targets sfml-audio )
list(APPEND _cmake_import_check_files_for_sfml-audio "${_IMPORT_PREFIX}/./sfml-audio.framework/Versions/2.6.2/sfml-audio" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
