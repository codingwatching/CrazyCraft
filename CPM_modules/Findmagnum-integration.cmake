include(/home/ati/Desktop/code/lol/lib/FastNoise2/cmake/CPM.cmake)
CPMAddPackage(NAME;magnum-integration;GITHUB_REPOSITORY;mosra/magnum-integration;GIT_TAG;789f8132842536f077548bc4f2d2c3685e9f491e;GIT_SUBMODULES;src;EXCLUDE_FROM_ALL;YES;OPTIONS;BUILD_STATIC ON;WITH_IMGUI ON)
set(magnum-integration_FOUND TRUE)