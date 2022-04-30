#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "FastNoise2::FastNoise" for configuration "Debug"
set_property(TARGET FastNoise2::FastNoise APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(FastNoise2::FastNoise PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libFastNoiseD.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS FastNoise2::FastNoise )
list(APPEND _IMPORT_CHECK_FILES_FOR_FastNoise2::FastNoise "${_IMPORT_PREFIX}/lib/libFastNoiseD.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
