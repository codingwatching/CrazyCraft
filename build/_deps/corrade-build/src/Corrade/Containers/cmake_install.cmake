# Install script for directory: /home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Corrade/Containers" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/AnyReference.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/Array.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/ArrayTuple.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/ArrayView.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/ArrayViewStl.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/ArrayViewStlSpan.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/BigEnumSet.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/BigEnumSet.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/constructHelpers.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/Containers.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/EnumSet.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/EnumSet.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/GrowableArray.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/initializeHelpers.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/LinkedList.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/MoveReference.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/Optional.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/OptionalStl.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/Pair.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/PairStl.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/Pointer.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/PointerStl.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/Reference.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/ScopeGuard.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/sequenceHelpers.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/StaticArray.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/StridedArrayView.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/String.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/StringStl.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/StringView.h"
    "/home/ati/Desktop/code/lol/build/_deps/corrade-src/src/Corrade/Containers/Tags.h"
    )
endif()

