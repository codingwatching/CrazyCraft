#include "eog/Renderer.h"
#include <GLFW/glfw3.h>

#include <iostream>

#include "eog/VertexBuffer.h"
#include "eog/VertexArray.h"
#include "eog/IndexBuffer.h"
#include "eog/Shader.h"

#include "eog/Texture.h"
#include "input/Input.h"

#include "glm/glm.hpp"

#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include "game/game.h"


glm::vec2 aspect;
GLFWwindow* InitWindow()
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        return nullptr;
    }


    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    GLFWwindow* window = glfwCreateWindow( 960, 540, "CrazyCraft", NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window.\n" );
        glfwTerminate();
        return nullptr;

    }
    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{

		 std::cout << "Failed to initialize GLAD.\n";
         glfwTerminate();
         return nullptr;
	}

    std::cout << "Using openGL Version: " << glGetString(GL_VERSION) << std::endl;

    // Ensure we can capture the escape key being pressed below
            //glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
          Input::loadCallbacks(window);

    return window;
}

bool mousecap = true;
glm::vec3 pos;
glm::vec2 rot;

void input(GLFWwindow* window){

if (mousecap){
          
          if (Input::mouseY < -90)
            {
                Input::mouseY = -90;
            }

            if (Input::mouseY > 90)
            {
                Input::mouseY = 90;
            }

            rot.x = Input::mouseY * 0.5;
            rot.y = Input::mouseX * 0.5;
             
            
        }
        glm::vec3 front;
        front.x = cos(glm::radians(rot.y)) * cos(glm::radians(rot.x));
        //front.y = sin(glm::radians(rot.x));
        front.z = sin(glm::radians(rot.y)) * cos(glm::radians(rot.x));
        front = glm::normalize(front);
        glm::vec3  right = glm::normalize(glm::cross(front, glm::vec3(0,1,0))); 
       
        float velocity = 2.5f;
        if (Input::isKeyDown(GLFW_KEY_W)){

            pos -= right * velocity;
        }
        
        if (Input::isKeyDown(GLFW_KEY_S)){

            pos += right * velocity;
        }
       
        if (Input::isKeyDown(GLFW_KEY_A)){

            pos -= front * velocity;
        }
        if (Input::isKeyDown(GLFW_KEY_D)){


            pos += front * velocity;
        }
         if (Input::isKeyDown(GLFW_KEY_LEFT_SHIFT)){

            pos -= glm::vec3(0,1,0) * velocity;
        }
         if (Input::isKeyDown(GLFW_KEY_SPACE)){

            pos += glm::vec3(0,1,0) * velocity;
            
        }
         if (Input::isKeyDown(GLFW_KEY_ESCAPE)){

           glfwSetWindowShouldClose(window,GL_TRUE);
        }

}

int main()
{
    
    GLFWwindow* window = InitWindow();
    if (!window)
        return -1;
        

  /*  glm::vec3 poses[] = {
        // front
        glm::vec3(-100.0f, -100.0f,1),
        glm::vec3(100.0f, -100.0f,1),
        glm::vec3(100.0f, 100.0f,1),
        glm::vec3(-100.0f, 100.0f,1)
      
    };
    glm::vec2 uvs[]{
        glm::vec2(0.0f, 0.0f),
        glm::vec2(1.0f, 0.0f),
        glm::vec2(1.0f, 1.0f),
        glm::vec2(0.0f, 1.0f)
    };*/

float vert[]{
-50.0f, -50.0f,1,0.0f, 0.0f,
50.0f, -50.0f,1,1.0f, 0.0f,
50.0f, 50.0f,1,1.0f, 1.0f,
-50.0f, 50.0f,1,0.0f, 1.0f
};

    unsigned int tris[] = {
        0, 1, 2,
        2, 3, 0,

    };


    GLCall( glEnable(GL_BLEND) );
    GLCall( glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) );

    VertexArray va;
   VertexBuffer vb(vert,sizeof(vert));
   IndexBuffer ib(tris,sizeof(tris));
     //   CrazyCraft::Mesh::build(poses,uvs,tris,vb,ib);
    

     

        glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
            {
                aspect.x = width;
                aspect.y = height;
                glViewport(-width, -height, width, height);
            });


        // projection matrix
        aspect.x = 960; 
        aspect.y = 540;
        glm::mat4 proj = glm::perspective<float>(45.0f,aspect.x /aspect.y, 1.0f, 10000.0f);

        // view matrix
        glm::mat4 ident = glm::mat4(1.0f);
        glm::mat4 view = ident;

        VertexBufferLayout layout;
        layout.AddFloat(3);
        layout.AddFloat(2);
        glEnable(GL_DEPTH_TEST);
        va.AddBuffer(vb, layout);

        Shader shader("res/shaders/Basic.shader");
        shader.Bind();
        shader.SetUniform4f("u_Color", 0.0f, 0.3f, 0.8f, 1.0f);

        Texture texture("res/textures/phone.png");
        texture.Bind();
        shader.SetUniform1i("u_Texture", 0);
    
        Renderer renderer;


        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplGlfwGL3_Init(window, true);
        ImGui::StyleColorsDark();

        
        do {
            glClearColor(0.5,0.5,1,1);
            renderer.Clear();

            ImGui_ImplGlfwGL3_NewFrame();

            input(window);

            // model matrix
            proj = glm::perspective<float>(45.0f,aspect.x /aspect.y, 1.0f, 10000.0f);
            glm::mat4 model = glm::mat4(1.0f);
         
            view = glm::rotate(ident, glm::radians(rot.x), {1, 0, 0});
            view = glm::rotate(view, glm::radians(rot.y), {0, 1, 0});
            //view = glm::rotate(view, glm::radians(rot.z), {0, 0, 1});

            view = glm::translate(view, -pos);

            glm::mat4 mvp = proj * view * model;

            shader.Bind();
            shader.SetUniformMat4f("u_MVP", mvp);

            renderer.Draw(va, ib, shader);

            {
                ImGui::DragFloat3("Camera Translation", &pos.x, 0.0f, 960.0f);
                ImGui::DragFloat2("Camera Rotation", &rot.x, 0.0f, 960.0f);
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            }

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


