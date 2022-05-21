struct Camera
{
	glm::vec3 pos;
	glm::vec2 rot;
	glm::mat4 proj;
	glm::mat4 ident;
	glm::mat4 view;
bool s = true;
unsigned int shader;
unsigned int invshader;
int ftimer = 0;

	Camera()
	{
		// view matrix
		ident = glm::mat4(1.0f);

		pos = {0, 0, 0};
		rot = {0, 0};
	ShaderProgramSource source = ParseShader("../res/shaders/Basic.shader");
	shader = CreateShader(source.VertexSource, source.FragmentSource);
	ShaderProgramSource invsource = ParseShader("../res/shaders/Cinvert.shader");
	invshader = CreateShader(invsource.VertexSource, invsource.FragmentSource);
	glUseProgram(shader);

		GLCall(int location = glGetUniformLocation(shader, "u_Texture"));
	if (location == -1)
		std::cout << "No active uniform variable with name " << "u_Texture" << " found" << std::endl;
	glUniform1i(location, 0);
	}

	void input(GLFWwindow *window)
	{
	
		if (Input::mouseY > 90)
			Input::mouseY = 90;
		if (Input::mouseY< -90)
			Input::mouseY = -90;

	rot.x = Input::mouseY;
	rot.y = Input::mouseX;


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

				glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
		if (Input::isKeyDown(GLFW_KEY_F4))
		{
if(ftimer > 10){
			s = !s;
ftimer = 0;
}

				if(s){
				glUseProgram(shader);
				}else{
				glUseProgram(invshader);
				}
		}
	ftimer++;
	}

	void updateMatrix(glm::vec2 aspect)
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