#ifndef MINECRAFT_CLONE_INPUT_H
#define MINECRAFT_CLONE_INPUT_H

#include <GLFW/glfw3.h>

namespace Input
{
	extern bool keyPressedData[GLFW_KEY_LAST];
	extern bool mouseButtonPressedData[GLFW_MOUSE_BUTTON_LAST];
	extern float mouseX;
	extern float mouseY;
	extern float mouseScrollX;
	extern float mouseScrollY;

	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	void mouseCallback(GLFWwindow* window, double xpos, double ypos);

	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

	void loadCallbacks(GLFWwindow* Window);

	bool isKeyDown(int key);

	bool isMouseButtonDown(int mouseButton);
}


#endif 