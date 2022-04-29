# Install script for directory: /home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ati/Desktop/code/lol/build/Debug/lib/libMagnum-d.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/AbstractResourceLoader.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/British.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/DimensionTraits.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/FileCallback.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Image.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/ImageView.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Magnum.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Mesh.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/PixelFormat.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/PixelStorage.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Resource.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/ResourceManager.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Sampler.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Tags.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Timeline.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Types.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/VertexFormat.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/visibility.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Array.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/configure.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/version.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/Animation/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/Math/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/Platform/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/DebugTools/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/GL/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/Primitives/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/SceneGraph/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/Shaders/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/ShaderTools/cmake_install.cmake")
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/Trade/cmake_install.cmake")

endif()

