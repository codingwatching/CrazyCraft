# Install script for directory: /home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/Math" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Angle.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Bezier.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/BoolVector.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Color.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Complex.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Constants.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/ConfigurationValue.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/CubicHermite.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Distance.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Dual.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/DualComplex.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/DualQuaternion.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Frustum.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Functions.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/FunctionsBatch.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Half.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Intersection.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Math.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/TypeTraits.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Matrix.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Matrix3.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Matrix4.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Quaternion.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Packing.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/PackingBatch.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Range.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/RectangularMatrix.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/StrictWeakOrdering.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Swizzle.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Tags.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Unit.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Vector.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Vector2.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Vector3.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/Math/Vector4.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ati/Desktop/code/lol/build/_deps/magnum-build/src/Magnum/Math/Algorithms/cmake_install.cmake")

endif()

