
# Add GLAD
add_subdirectory(glad)

# Add glfw
set(GLFW_INSTALL OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_USE_HYBRID_HPG OFF)
add_subdirectory(glfw)

# Add FastNoise2
set(FASTNOISE2_NOISETOOL OFF)
set(FASTNOISE2_TESTS OFF)
add_subdirectory(FastNoise2)

# Add glm
add_subdirectory(glm)