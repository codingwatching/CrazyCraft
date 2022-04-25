# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ati/Desktop/code/lol/_deps/glfw-src"
  "/home/ati/Desktop/code/lol/_deps/glfw-build"
  "/home/ati/Desktop/code/lol/_deps/glfw-subbuild/glfw-populate-prefix"
  "/home/ati/Desktop/code/lol/_deps/glfw-subbuild/glfw-populate-prefix/tmp"
  "/home/ati/Desktop/code/lol/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp"
  "/home/ati/Desktop/code/lol/_deps/glfw-subbuild/glfw-populate-prefix/src"
  "/home/ati/Desktop/code/lol/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ati/Desktop/code/lol/_deps/glfw-subbuild/glfw-populate-prefix/src/glfw-populate-stamp/${subDir}")
endforeach()
