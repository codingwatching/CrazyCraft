# Install script for directory: /home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives

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
    set(CMAKE_INSTALL_CONFIG_NAME "")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ati/Desktop/code/lol/lib/libMagnumPrimitives.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/Primitives" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Axis.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Capsule.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Circle.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Crosshair.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Cone.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Cube.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Cylinder.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Gradient.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Grid.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Icosphere.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Line.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Plane.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/Square.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/UVSphere.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Primitives/visibility.h"
    )
endif()

