# Install script for directory: /home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/ati/Desktop/code/lol/lib/libMagnumGL.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/Magnum/GL" TYPE FILE FILES
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/AbstractFramebuffer.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/AbstractObject.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/AbstractQuery.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/AbstractShaderProgram.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/AbstractTexture.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Attribute.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Buffer.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Context.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/CubeMapTexture.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/DefaultFramebuffer.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Extensions.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Framebuffer.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/GL.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Mesh.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/MeshView.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/OpenGL.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/PixelFormat.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Renderbuffer.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/RenderbufferFormat.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Renderer.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Sampler.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Shader.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Texture.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/TextureFormat.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/TimeQuery.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/Version.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/visibility.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/PipelineStatisticsQuery.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/RectangleTexture.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/BufferImage.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/PrimitiveQuery.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/TextureArray.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/TransformFeedback.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/DebugOutput.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/BufferTexture.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/BufferTextureFormat.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/CubeMapTextureArray.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/ImageFormat.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/MultisampleTexture.h"
    "/home/ati/Desktop/code/lol/_deps/magnum-src/src/Magnum/GL/SampleQuery.h"
    )
endif()

