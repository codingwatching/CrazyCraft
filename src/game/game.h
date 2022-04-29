#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "input/Input.h"

#include "stb_image/stb_image.h"

struct Renderdata
{
	unsigned int vao;
	unsigned int ibo;
};

struct Vertex
{
	glm::vec3 pos;
	glm::vec2 uv;

	Vertex(glm::vec3 _pos, glm::vec2 _uv)
	{
		pos = _pos;
		uv = _uv;
	}
};

