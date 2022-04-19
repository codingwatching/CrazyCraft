#include <game/world/Chunk.h>

#include "input/Input.h"

#include "stb_image/stb_image.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include <opengl/shader.h>
#include <opengl/window.h>
#include <opengl/texture.h>
#include <opengl/camera.h>



int main()
{
    
    GLFWwindow* window = InitWindow();
    if (!window)
        return -1;    

    Camera c;

   Chunk ch;

    ch.UpdateRenderData();

    glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
        {
            aspect.x = width;
            aspect.y = height;
            glViewport(0, 0, width, height);
        });

        //aspect ratio
        aspect.x = 960; 
        aspect.y = 540;

       
        glEnable(GL_DEPTH_TEST);//enable stuff
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        unsigned int shader;
        ShaderProgramSource source = ParseShader("../res/shaders/Basic.shader");
        shader = CreateShader(source.VertexSource, source.FragmentSource);
        GLCall( glUseProgram(shader) );
       

        Texture tex;
        tex.parse("../res/textures/minecraft.png");

        tex.bind(0);

        GLCall( int location = glGetUniformLocation(shader, "u_Texture") );
        if (location == -1)
        std::cout << "No active uniform variable with name " << "u_Texture" << " found" << std::endl;
        GLCall( glUniform1i(location, 0) );

        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplGlfwGL3_Init(window, true);
        ImGui::StyleColorsDark();

        do {
            glClearColor(0.5,0.5,1,1);
            GLCall( glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

            ImGui_ImplGlfwGL3_NewFrame();

            c.input(window);

            c.updateMatrix(shader,aspect);


           ch.render();


            ImGui::DragFloat3("Camera Translation", &c.pos.x, 0.0f, 960.0f);
            ImGui::DragFloat2("Camera Rotation", &c.rot.x, 0.0f, 960.0f);
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

            ImGui::Render();
            ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());

            // Swap buffers
            glfwSwapBuffers(window);
            glfwPollEvents();
        } 
        while(!glfwWindowShouldClose(window));

  

    // Close OpenGL window and terminate GLFW
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
    return 0;
}