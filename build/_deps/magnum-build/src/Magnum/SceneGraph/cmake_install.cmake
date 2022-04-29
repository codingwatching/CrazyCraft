# Install script for directory: /home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ati/Desktop/code/lol/build/Debug/lib/libMagnumSceneGraph-d.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/SceneGraph" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractFeature.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractFeature.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractGroupedFeature.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractObject.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTransformation.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslation.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotation2D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotation3D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotationScaling2D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AbstractTranslationRotationScaling3D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Animable.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Animable.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/AnimableGroup.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Camera.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Camera.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Drawable.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Drawable.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/DualComplexTransformation.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/DualQuaternionTransformation.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation2D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation2D.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation3D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/RigidMatrixTransformation3D.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/FeatureGroup.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/FeatureGroup.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation2D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation2D.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation3D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/MatrixTransformation3D.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Object.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Object.hpp"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/Scene.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/SceneGraph.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/TranslationTransformation.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/TranslationRotationScalingTransformation2D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/TranslationRotationScalingTransformation3D.h"
    "/home/ati/Desktop/code/lol/build/_deps/magnum-src/src/Magnum/SceneGraph/visibility.h"
    )
endif()

