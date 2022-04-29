# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ati/Desktop/code/lol/build/_deps/magnum-src"
  "/home/ati/Desktop/code/lol/build/_deps/magnum-build"
  "/home/ati/Desktop/code/lol/build/_deps/magnum-subbuild/magnum-populate-prefix"
  "/home/ati/Desktop/code/lol/build/_deps/magnum-subbuild/magnum-populate-prefix/tmp"
  "/home/ati/Desktop/code/lol/build/_deps/magnum-subbuild/magnum-populate-prefix/src/magnum-populate-stamp"
  "/home/ati/Desktop/code/lol/build/_deps/magnum-subbuild/magnum-populate-prefix/src"
  "/home/ati/Desktop/code/lol/build/_deps/magnum-subbuild/magnum-populate-prefix/src/magnum-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ati/Desktop/code/lol/build/_deps/magnum-subbuild/magnum-populate-prefix/src/magnum-populate-stamp/${subDir}")
endforeach()
