cmake_minimum_required(VERSION 3.10)

# set the project name
project(Tutorial)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*/*.cpp" "src/*/*/*.cpp" "src/*/*/*/*.cpp")
file (GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/*.h" "src/*/*.h" "src/*/*/*.h" "src/*/*/*/*.h" "src/*.hpp" "src/*/*.hpp" "src/*/*/*.hpp" "src/*/*/*/*.hpp")

set (INCLUDE_DIRS "")
foreach (_headerFile ${HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES INCLUDE_DIRS)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE ${INCLUDE_DIRS})

add_compile_definitions(_DEBUG)

include_directories("src")
include_directories("lib/include")
include_directories("src/vendor")
add_subdirectory(lib/FastNoise2)
add_subdirectory(lib/glad)

target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE glad)
target_link_libraries(main PRIVATE FastNoise2)