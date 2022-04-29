#ifndef IMPORTANT
#define IMPORTANT

#define _DEBUG

#include <opengl/debug.h>
#include <opengl/shader.h>
#include <opengl/window.h>
#include <opengl/texture.h>
#include <opengl/camera.h>

unsigned int shader;

void Init()
{

	glEnable(GL_DEPTH_TEST);//enable stuff
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
	shader = CreateShader(source.VertexSource, source.FragmentSource);
	GLCall(glUseProgram(shader));
       

	Texture tex;
	tex.parse("res/textures/minecraft.png");

	tex.bind(0);

	GLCall(int location = glGetUniformLocation(shader, "u_Texture"));
	if (location == -1)
		std::cout << "No active uniform variable with name " << "u_Texture" << " found" << std::endl;
	GLCall(glUniform1i(location, 0));
}

#endif