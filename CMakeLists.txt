cmake_minimum_required(VERSION 3.10)

# set the project name
project(CrazyCraft)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

set(RUNTIME_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for dlls and binaries")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for binaries")
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for dlls")

IF(NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin CACHE PATH "Directory for dlls and binaries")
endif()

add_subdirectory(lib)

file(GLOB_RECURSE PROJECT_SOURCE_FILES src/*.hpp src/*.h src/*.cpp)
add_executable(CrazyCraft ${PROJECT_SOURCE_FILES})
target_include_directories(CrazyCraft PUBLIC src)
target_include_directories(CrazyCraft PUBLIC src/vendor)
target_include_directories(CrazyCraft PUBLIC src/game)
target_include_directories(CrazyCraft PUBLIC src/game/world)

target_link_libraries(CrazyCraft PUBLIC glad glfw glm FastNoise)