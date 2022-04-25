# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/ati/Desktop/code/lol/_deps/corrade-src"
  "/home/ati/Desktop/code/lol/_deps/corrade-build"
  "/home/ati/Desktop/code/lol/_deps/corrade-subbuild/corrade-populate-prefix"
  "/home/ati/Desktop/code/lol/_deps/corrade-subbuild/corrade-populate-prefix/tmp"
  "/home/ati/Desktop/code/lol/_deps/corrade-subbuild/corrade-populate-prefix/src/corrade-populate-stamp"
  "/home/ati/Desktop/code/lol/_deps/corrade-subbuild/corrade-populate-prefix/src"
  "/home/ati/Desktop/code/lol/_deps/corrade-subbuild/corrade-populate-prefix/src/corrade-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/ati/Desktop/code/lol/_deps/corrade-subbuild/corrade-populate-prefix/src/corrade-populate-stamp/${subDir}")
endforeach()
