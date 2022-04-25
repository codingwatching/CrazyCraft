# Install script for directory: /home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ati/Desktop/code/lol/lib/libMagnumTrade.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/Trade" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/AbstractImporter.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/AbstractImageConverter.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/AbstractSceneConverter.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/AnimationData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/ArrayAllocator.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/CameraData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/Data.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/FlatMaterialData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/ImageData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/LightData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/MaterialData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/MaterialLayerData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/MeshData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/MeshObjectData2D.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/MeshObjectData3D.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/ObjectData2D.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/ObjectData3D.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/PbrClearCoatMaterialData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/PbrMetallicRoughnessMaterialData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/PbrSpecularGlossinessMaterialData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/PhongMaterialData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/SceneData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/SkinData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/TextureData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/Trade.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/visibility.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/AbstractMaterialData.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/MeshData2D.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/Trade/MeshData3D.h"
    )
endif()

