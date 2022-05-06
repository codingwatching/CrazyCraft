#include "Input.h"
#include <iostream>
#include "glm/glm.hpp"

namespace Input
{
	GLFWwindow* win;
	bool mouseButtonPressedData[7] = {};
	glm::ivec2 lastMousePos = {0, 0};
	float mouseX = 0.0f;
	float mouseY = 0.0f;
	float mouseScrollX = 0.0f;
	float mouseScrollY = 0.0f;


	void mouseCallback(GLFWwindow* window, double xpos, double ypos)
	{
		glm::ivec2 currentMousePos = { static_cast<int>(xpos), static_cast<int>(ypos) };
		glm::ivec2 delta;

		if (lastMousePos != currentMousePos)
		{
			delta = currentMousePos - lastMousePos;

			lastMousePos = currentMousePos;
			
		}
		//std::cout << delta.x << " " << delta.y << std::endl;

		mouseX += delta.x;
		mouseY += delta.y;
	}

	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (button >= 0 && button < GLFW_MOUSE_BUTTON_LAST)
		{
			mouseButtonPressedData[button] = (action == GLFW_PRESS);
		}
	}

	void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		mouseScrollX = (float) xoffset;
		mouseScrollY = (float) yoffset;
	}

	void loadCallbacks(GLFWwindow* Window)
	{
		glfwSetCursorPosCallback(Window, &mouseCallback);
		glfwSetMouseButtonCallback(Window, &mouseButtonCallback);
		glfwSetScrollCallback(Window, &mouseScrollCallback);
		win = Window;
	}

	bool isKeyDown(int key)
	{
		if (key >= 0 && key < GLFW_KEY_LAST)
		{
			return glfwGetKey(win, key) == GLFW_PRESS;
		}

		return false;
	}

	bool isMouseButtonDown(int mouseButton)
	{
		if (mouseButton >= 0 && mouseButton < GLFW_MOUSE_BUTTON_LAST)
		{
			return mouseButtonPressedData[mouseButton];
		}

		return false;
	}
}
