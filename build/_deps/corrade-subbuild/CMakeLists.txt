# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.23.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(corrade-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/usr/bin/git]==])
set(GIT_VERSION_STRING [==[2.36.0]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/usr/bin/git;2.36.0]==]
)


include(ExternalProject)
ExternalProject_Add(corrade-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_SUBMODULES" "src" "GIT_REPOSITORY" "https://github.com/mosra/corrade.git" "GIT_TAG" "a8065db3c55aec214aa4e4887c4073289b2988e2"
                    SOURCE_DIR          "/home/ati/Desktop/code/lol/build/_deps/corrade-src"
                    BINARY_DIR          "/home/ati/Desktop/code/lol/build/_deps/corrade-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


