#ifndef IMPORTANT
#define IMPORTANT

#define _DEBUG

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


	Texture tex;
	tex.parse("../res/textures/minecraft.png");

	tex.bind(0);


}

#endif