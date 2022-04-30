//#include <game/world/Chunk.h>
#include <game/world/World.h>
#include <important.h>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

int main()
{

	GLFWwindow *window = InitWindow();
	if (!window)
		return -1;

	Camera c;

	Chunk ch(glm::ivec3(0, 0, 0));
	Chunk ch2(glm::ivec3(1, 0, 0));

	ch.UpdateRenderData();
	ch2.UpdateRenderData();


	glfwSetWindowSizeCallback(window, [](GLFWwindow *window, int width, int height)
	{
		aspect.x = width;
		aspect.y = height;
		glViewport(0, 0, width, height);
	});

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//aspect ratio
	aspect.x = 960;
	aspect.y = 540;

	Init();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui_ImplGlfwGL3_Init(window, true);
	ImGui::StyleColorsDark();

	do
	{
		glClearColor(0.5, 0.5, 1, 1);
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		//ImGui_ImplGlfwGL3_NewFrame();
		c.input(window);


		c.updateMatrix(shader, aspect);

		ch.render();
		ch2.render();

		//ImGui::DragFloat3("Camera Translation", &c.pos.x, 0.0f, 960.0f);
		//ImGui::DragFloat2("Camera Rotation", &c.rot.x, 0.0f, 960.0f);
		//ImGui::Text("Application average: %.1f FPS", ImGui::GetIO().Framerate);

		//ImGui::Render();
		//ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (!glfwWindowShouldClose(window));



	// Close OpenGL window and terminate GLFW
	ImGui_ImplGlfwGL3_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}