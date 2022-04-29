# Install script for directory: /home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ati/Desktop/code/lol/build/Debug/lib/libMagnumShaders-d.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/Shaders" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/DistanceFieldVector.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/DistanceFieldVectorGL.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/Flat.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/FlatGL.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/Generic.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/GenericGL.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/MeshVisualizer.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/MeshVisualizerGL.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/Phong.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/PhongGL.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/Shaders.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/Vector.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/VectorGL.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/VertexColorGL.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/visibility.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Shaders/VertexColor.h"
    )
endif()

