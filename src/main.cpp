#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <game/world/Chunk.h>

#include "input/Input.h"

#include "stb_image/stb_image.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw_gl3.h"

#define ASSERT(x) if (!(x)) assert(false)
void inline GLClearError()
{
    while (glGetError() != GL_NO_ERROR);
}

bool inline GLCheckError(std::string loc)
{
    while (GLenum error = glGetError())
    {
        
        std::cout << "[OpenGL Error] in line '" << loc << "':";
          switch(error) {
              case GL_INVALID_ENUM :
                  std::cout << "GL_INVALID_ENUM : An unacceptable value is specified for an enumerated argument.";
                  break;
              case GL_INVALID_VALUE :
                  std::cout << "GL_INVALID_VALUE : A numeric argument is out of range.";
                  break;
              case GL_INVALID_OPERATION :
                  std::cout << "GL_INVALID_OPERATION : The specified operation is not allowed in the current state.";
                  break;
              case GL_INVALID_FRAMEBUFFER_OPERATION :
                  std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION : The framebuffer object is not complete.";
                  break;
              case GL_OUT_OF_MEMORY :
                  std::cout << "GL_OUT_OF_MEMORY : There is not enough memory left to execute the command.";
                  break;
              case GL_STACK_UNDERFLOW :
                  std::cout << "GL_STACK_UNDERFLOW : An attempt has been made to perform an operation that would cause an internal stack to underflow.";
                  break;
              case GL_STACK_OVERFLOW :
                  std::cout << "GL_STACK_OVERFLOW : An attempt has been made to perform an operation that would cause an internal stack to overflow.";
                  break;
              default :
                  std::cout << "Unrecognized error" << error;
          }
          std::cout << std::endl;
          return false;
    }
    return true;
}



#ifdef _DEBUG
#define GLCall(x) GLClearError(); x; ASSERT(GLCheckError(#x))
#else
#define GLCall(x) x
#endif

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

enum ShaderType
{
    NONE = -1, VERTEX = 0, FRAGMENT = 1
};

struct ShaderProgramSource ParseShader(const std::string& filepath)
{

    std::ifstream stream(filepath);
    std::string line;
    std::stringstream ss[2];
    ShaderType type = NONE;

    if(!stream.is_open())
        std::cout << "[Error]failed to open the shader" << std::endl;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = FRAGMENT;
        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }
std::cout << ss[0].str() << std::endl;
std::cout << ss[1].str() << std::endl;

    register ShaderProgramSource s = { ss[0].str(), ss[1].str() };
    return s;
}

unsigned int CompileShader(unsigned int type, const std::string& source)
{
    GLCall( unsigned int id = glCreateShader(type) );
    const char* src = source.c_str();
    GLCall( glShaderSource(id, 1, &src, nullptr) );
    GLCall( glCompileShader(id) );

    // Error handling
    int result;
    GLCall( glGetShaderiv(id, GL_COMPILE_STATUS, &result) );
    std::cout << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader compile status: " << result << std::endl;
    if ( result == GL_FALSE )
    {
        int length;
        GLCall( glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length) );
        char* message = (char*) alloca(length * sizeof(char));
        GLCall( glGetShaderInfoLog(id, length, &length, message) );
        std::cout 
            << "Failed to compile "
            << (type == GL_VERTEX_SHADER ? "vertex" : "fragment")
            << "shader"
            << std::endl;
        std::cout << message << std::endl;
        GLCall( glDeleteShader(id) );
        return 0;
    }

    return id;
}

unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    // create a shader program
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall( glAttachShader(program, vs) );
    GLCall( glAttachShader(program, fs) );

    GLCall( glLinkProgram(program) );

    GLint program_linked;

    GLCall( glGetProgramiv(program, GL_LINK_STATUS, &program_linked) );
    std::cout << "Program link status: " << program_linked << std::endl;
    if (program_linked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        GLCall( glGetProgramInfoLog(program, 1024, &log_length, message) );
        std::cout << "Failed to link program" << std::endl;
        std::cout << message << std::endl;
    }

    GLCall( glValidateProgram(program) );

    GLCall( glDeleteShader(vs) );
    GLCall( glDeleteShader(fs) );

    return program;
}

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

            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
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
};
int main()
{
    
    GLFWwindow* window = InitWindow();
    if (!window)
        return -1;    

       




   Chunk ch;

    
    unsigned int vb;
    unsigned int va;
    unsigned int ib;

    GLCall( glGenVertexArrays(1, &va) );//VAO
    GLCall( glBindVertexArray(va) );

    GLCall( glGenBuffers(1, &vb) );//VBO
    GLCall( glBindBuffer(GL_ARRAY_BUFFER, vb) );
    GLCall( glBufferData(GL_ARRAY_BUFFER, sizeof(ch.verticies), &ch.verticies, GL_STATIC_DRAW) );
   
    GLCall( glGenBuffers(1, &ib) );//IBO
    GLCall( glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib) );
    GLCall( glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ch.tris) * sizeof(unsigned int),&ch.tris, GL_STATIC_DRAW) );

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
        GLCall( glEnable(GL_BLEND) );
        GLCall( glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA) );

        GLCall( glEnableVertexAttribArray(0) );//first argument
        GLCall( glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                                   sizeof(Vertex),(int*)0));
        
        GLCall( glEnableVertexAttribArray(1) );//second argument
        GLCall( glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
                                   sizeof(Vertex),(int*)(sizeof(float)*3)));
        
        unsigned int shader;
        ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
        shader = CreateShader(source.VertexSource, source.FragmentSource);
        GLCall( glUseProgram(shader) );
       
        //texture start
        Texture tex;
        stbi_set_flip_vertically_on_load(1);
        tex.m_LocalBuffer = stbi_load("res/textures/minecraft.png", &tex.m_Width, &tex.m_Height, &tex.m_BPP, 4);
        if (!tex.m_LocalBuffer){
          std::cout << "[Error]can't load texture at: " << "res/textures/minecraft.png" << std::endl;

        }
        GLCall( glGenTextures(1, &tex.rid) );
        GLCall( glBindTexture(GL_TEXTURE_2D, tex.rid) ); // Bind without slot selection

        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST) );//settings
        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST) );
        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE) );
        GLCall( glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE) );

        GLCall( glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, tex.m_Width, tex.m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.m_LocalBuffer) );
        GLCall( glBindTexture(GL_TEXTURE_2D, 0) );//unbind

        if (tex.m_LocalBuffer)
        stbi_image_free(tex.m_LocalBuffer);
    //texture end

        GLCall( glActiveTexture(GL_TEXTURE0) );
        GLCall( glBindTexture(GL_TEXTURE_2D, tex.rid) );

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


            GLCall( glBindVertexArray(va) );
            GLCall( glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, nullptr) );


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


