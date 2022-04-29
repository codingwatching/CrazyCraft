# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ati/Desktop/code/lol/build/_deps/imnodes-src"
  "/home/ati/Desktop/code/lol/build/_deps/imnodes-build"
  "/home/ati/Desktop/code/lol/build/_deps/imnodes-subbuild/imnodes-populate-prefix"
  "/home/ati/Desktop/code/lol/build/_deps/imnodes-subbuild/imnodes-populate-prefix/tmp"
  "/home/ati/Desktop/code/lol/build/_deps/imnodes-subbuild/imnodes-populate-prefix/src/imnodes-populate-stamp"
  "/home/ati/Desktop/code/lol/build/_deps/imnodes-subbuild/imnodes-populate-prefix/src"
  "/home/ati/Desktop/code/lol/build/_deps/imnodes-subbuild/imnodes-populate-prefix/src/imnodes-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ati/Desktop/code/lol/build/_deps/imnodes-subbuild/imnodes-populate-prefix/src/imnodes-populate-stamp/${subDir}")
endforeach()
