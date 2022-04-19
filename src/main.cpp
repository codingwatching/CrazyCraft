#include <game/world/Chunk.h>

#include "input/Input.h"

#include "stb_image/stb_image.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#include <opengl/shader.h>

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

           // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
            Input::loadCallbacks(window);

    return window;
}

bool mousecap = true;
glm::vec3 pos;
glm::vec2 rot;

void input(GLFWwindow* window){

if (mousecap){
          
          if (Input::mouseY < -90*2)
            {
                Input::mouseY = -90*2;
            }

            if (Input::mouseY > 90*2)
            {
                Input::mouseY = 90*2;
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
        float sbonus = 3.;
        float velocity = 2.5f;
        if(Input::isKeyDown(GLFW_KEY_LEFT_CONTROL) ||Input::isKeyDown(GLFW_KEY_RIGHT_CONTROL)){
            velocity += sbonus;
        }
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
glm::mat4 proj;
glm::mat4 ident;
glm::mat4 view;


void updateMatrix(unsigned int shader){
   // model matrix
            proj = glm::perspective<float>(45.0f,aspect.x /aspect.y, 1.0f, 10000.0f);
            glm::mat4 model = glm::mat4(1.0f);
         
            view = glm::rotate(ident, glm::radians(rot.x), {1, 0, 0});
            view = glm::rotate(view, glm::radians(rot.y), {0, 1, 0});
            //view = glm::rotate(view, glm::radians(rot.z), {0, 0, 1});

            view = glm::translate(view, -pos);

            glm::mat4 mvp = proj * view * model;

              GLCall( int location = glGetUniformLocation(shader, "u_MVP") );
        if (location == -1)
        std::cout << "No active uniform variable with name " << "u_MVP" << " found" << std::endl;
        GLCall( glUniformMatrix4fv(location, 1, GL_FALSE, &mvp[0][0]) );
}
struct Texture{
    unsigned int rid;
    int m_Width, m_Height, m_BPP;
    unsigned char* m_LocalBuffer;

    void parse(std::string fname){
        stbi_set_flip_vertically_on_load(1);
        m_LocalBuffer = stbi_load(fname.c_str(), &m_Width, &m_Height, &m_BPP, 4);
        if (!m_LocalBuffer){
          std::cout << "[Error]can't load texture at: " << fname << std::endl;

        }
        GLCall( glGenTextures(1, &rid) );
        GLCall( glBindTexture(GL_TEXTURE_2D, rid) ); // Bind without slot selection

        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST) );//settings
        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST) );
        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE) );
        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) );

        GLCall( glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_LocalBuffer) );
        GLCall( glBindTexture(GL_TEXTURE_2D, 0) );//unbind

        if (m_LocalBuffer)
        stbi_image_free(m_LocalBuffer);
    }

    void bind(int slot){
        GLCall( glActiveTexture(GL_TEXTURE0 + slot) );
        GLCall( glBindTexture(GL_TEXTURE_2D,rid) );
    }

    void unbind(int slot){
        GLCall( glBindTexture(GL_TEXTURE_2D,0) );
    }
};
int main()
{
    
    GLFWwindow* window = InitWindow();
    if (!window)
        return -1;    

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

        // view matrix
        ident = glm::mat4(1.0f);
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

            input(window);

            updateMatrix(shader);


           ch.render();


            ImGui::DragFloat3("Camera Translation", &pos.x, 0.0f, 960.0f);
            ImGui::DragFloat2("Camera Rotation", &rot.x, 0.0f, 960.0f);
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


