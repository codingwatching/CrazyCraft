glm::vec2 aspect;

GLFWwindow* InitWindow()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		return nullptr;
	}


	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(960, 540, "CrazyCraft", NULL, NULL);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate();
		return nullptr;

	}

	glfwMakeContextCurrent(window);

	// Initialize GLAD
	if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
	{

		std::cout << "Failed to initialize GLAD.\n";
		glfwTerminate();
		return nullptr;
	}

	std::cout << "Using openGL Version: " << glGetString(GL_VERSION) << std::endl;

	// glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
	Input::loadCallbacks(window);

	return window;
}