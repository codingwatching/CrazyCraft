# Install script for directory: /home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ati/Desktop/code/lol/lib/libCorradeUtility.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Corrade/Utility" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Algorithms.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Arguments.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/AbstractHash.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Assert.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Configuration.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/ConfigurationGroup.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/ConfigurationValue.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Debug.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/DebugStl.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Directory.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Endianness.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/EndiannessBatch.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Format.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/FormatStl.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Macros.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Memory.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Move.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/MurmurHash2.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Resource.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Sha1.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/String.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/StlForwardArray.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/StlForwardString.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/StlForwardTuple.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/StlForwardVector.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/StlMath.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/System.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/TypeTraits.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Unicode.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/utilities.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Utility.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/VisibilityMacros.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/visibility.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/FileWatcher.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/Tweakable.h"
    "/home/ati/Desktop/code/lol/_deps/corrade-src/src/Corrade/Utility/TweakableParser.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/home/ati/Desktop/code/lol/bin/corrade-rc")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/corrade-rc")
    endif()
  endif()
endif()

