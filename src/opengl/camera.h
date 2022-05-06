struct Camera
{
	glm::vec3 pos;
	glm::vec2 rot;
	glm::mat4 proj;
	glm::mat4 ident;
	glm::mat4 view;

	Camera()
	{
		// view matrix
		ident = glm::mat4(1.0f);

		pos = {0, 0, 0};
		rot = {0, 0};
	}

	void input(GLFWwindow *window)
	{
		rot.x = Input::mouseY;
		rot.y = Input::mouseX;

		if (rot.x > 90)
			rot.x = 90;
		if (rot.x < -90)
			rot.x = -90;

		glm::vec3 front;
		front.x = cos(glm::radians(rot.y)) * cos(glm::radians(rot.x));
		// front.y = sin(glm::radians(rot.x));
		front.z = sin(glm::radians(rot.y)) * cos(glm::radians(rot.x));
		front = glm::normalize(front);
		glm::vec3 right = glm::normalize(glm::cross(front, glm::vec3(0, 1, 0)));
		float sbonus = 3.;
		float velocity = 2.5f;
		if (Input::isKeyDown(GLFW_KEY_LEFT_CONTROL) || Input::isKeyDown(GLFW_KEY_RIGHT_CONTROL))
		{
			velocity += sbonus;
		}
		if (Input::isKeyDown(GLFW_KEY_W))
		{

			pos -= right * velocity;
		}

		if (Input::isKeyDown(GLFW_KEY_S))
		{

			pos += right * velocity;
		}

		if (Input::isKeyDown(GLFW_KEY_A))
		{

			pos -= front * velocity;
		}
		if (Input::isKeyDown(GLFW_KEY_D))
		{

			pos += front * velocity;
		}
		if (Input::isKeyDown(GLFW_KEY_LEFT_SHIFT))
		{

			pos -= glm::vec3(0, 1, 0) * velocity;
		}
		if (Input::isKeyDown(GLFW_KEY_SPACE))
		{

			pos += glm::vec3(0, 1, 0) * velocity;
		}
		if (Input::isKeyDown(GLFW_KEY_ESCAPE))
		{

			glfwSetWindowShouldClose(window, GL_TRUE);
		}

	}

	void updateMatrix(unsigned int shader, glm::vec2 aspect)
	{
		// model matrix
		proj = glm::perspective<float>(45.0f, aspect.x / aspect.y, 1.0f, 10000.0f);
		glm::mat4 model = glm::mat4(1.0f);

		view = glm::rotate(ident, glm::radians(rot.x), {1, 0, 0});
		view = glm::rotate(view, glm::radians(rot.y), {0, 1, 0});
		// view = glm::rotate(view, glm::radians(rot.z), {0, 0, 1});

		view = glm::translate(view, -pos);

		glm::mat4 mvp = proj * view * model;

		GLCall(int location = glGetUniformLocation(shader, "u_MVP"));
		if (location == -1)
			std::cout << "No active uniform variable with name "
					  << "u_MVP"
					  << " found" << std::endl;
		GLCall(glUniformMatrix4fv(location, 1, GL_FALSE, &mvp[0][0]));
	}
};