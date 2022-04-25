# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.23.1)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(magnum-integration-populate NONE)


# Pass through things we've already detected in the main project to avoid
# paying the cost of redetecting them again in ExternalProject_Add()
set(GIT_EXECUTABLE [==[/usr/bin/git]==])
set(GIT_VERSION_STRING [==[2.36.0]==])
set_property(GLOBAL PROPERTY _CMAKE_FindGit_GIT_EXECUTABLE_VERSION
  [==[/usr/bin/git;2.36.0]==]
)


include(ExternalProject)
ExternalProject_Add(magnum-integration-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_SUBMODULES" "src" "GIT_REPOSITORY" "https://github.com/mosra/magnum-integration.git" "GIT_TAG" "789f8132842536f077548bc4f2d2c3685e9f491e"
                    SOURCE_DIR          "/home/ati/Desktop/code/lol/_deps/magnum-integration-src"
                    BINARY_DIR          "/home/ati/Desktop/code/lol/_deps/magnum-integration-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
                    USES_TERMINAL_PATCH     YES
)


