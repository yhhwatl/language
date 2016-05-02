#include "platform.hpp"

// third-party libraries
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// standard C++ libraries
#include <cassert>
#include <iostream>
#include <stdexcept>
#include <cmath>
#include <vector>

#include "Shader.h"
#include "Program.h"
// constants
const glm::vec2 SCREEN_SIZE(800, 600);

// globals
GLFWwindow* gWindow = nullptr;
tdogl::Program* g_program = nullptr;
GLuint gVAO = 0;
GLuint gVBO = 0;

void initWindows();

// 加载顶点shader 像素shader 链接生成program
static void loadShaders() {
    std::vector<tdogl::Shader> m_sharde;
    m_sharde.push_back(tdogl::Shader::shaderFromFile(ResourcePath("vertex-shader.txt"), GL_VERTEX_SHADER));
    m_sharde.push_back(tdogl::Shader::shaderFromFile(ResourcePath("fragment-shader.txt"),GL_FRAGMENT_SHADER));
    g_program = new tdogl::Program(m_sharde);
}
// 加载一个三角形到VAO
static void loadTriangle(){
    //创建创建缓冲区对象VAO
    glGenVertexArrays(1,&gVAO);//生成一个对象的name。而name就是这个对象的引用。
//    通过对象的名字来引用它，其名字是一个无符号的整型标识符。
//    从OpenGL 3.1开始，所有的名字必须由OpenGL使用glGen*()函数之一来生成，不再接受用户定义的名字。
//    激活缓冲区对象VAO
    glBindVertexArray(gVAO);//将对象绑定到context上
    //创建VBO
    glGenBuffers(1,&gVBO);
    //任何VBO都需要先绑定到 GL_ARRAY_BUFFER 才可以对它进行操作
    glBindBuffer(GL_ARRAY_BUFFER,gVBO);
    GLfloat vertexData[] = {
      0.0f,0.8f,0.0f,
      -0.8f,-0.8f,0.0f,
      0.8f,-0.8f,0.0f,
    };
    //缓存三角形顶点数据到内存
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertexData),vertexData,GL_STATIC_DRAW);
    //开启vert属性
    glEnableVertexAttribArray(g_program->attrib("vert"));
    //使用vert数据 告诉OpenGl，编号为index的属性使用当前绑定在GL_ARRAY_BUFFER的VBO
    glVertexAttribPointer(g_program->attrib("vert"),3,GL_FLOAT,GL_FALSE,0,nullptr);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    
//    这个过程就像一个中介人的作用，而中介人就是GL_ARRAY_BUFFER。
//    我们可以这么想，glBindBuffer 设置了一个全局变量，
//    然后glVertexAttribPointer读取了这个全局变量并把它存储在VAO中，这个全局变量就是GL_ARRAY_BUFFER。
//    当调用完glVertexAttribPointer后，顶点属性已经知道了数据来源就是buf1，
//    它们之间就会直接联系，而不需要在通过GL_ARRAY_BUFFER。
}

static void Render(){
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(g_program->object());
    glBindVertexArray(gVAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
    glUseProgram(0);
    glfwSwapBuffers(gWindow);
}

void appMain()
{
    initWindows();
    loadShaders();
    loadTriangle();
    
    while(!glfwWindowShouldClose(gWindow)){
        
        glfwPollEvents();
        Render();
        
    }
}

int main(int argc, char const *argv[])
{
    try {
        appMain();
    } catch (const std::exception& e) {
        std::cerr << "ERROR:" << e.what() << std::endl;
    }   

    return EXIT_SUCCESS;
}



void OnError(int errorCode, const char* msg) {
    throw std::runtime_error(msg);
}

void initWindows()
{
    // initialise GLFW
    glfwSetErrorCallback(OnError);
    if(!glfwInit())
        throw std::runtime_error("glfwInit failed");
    
    // open a window with GLFW
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    gWindow = glfwCreateWindow((int)SCREEN_SIZE.x, (int)SCREEN_SIZE.y, "OpenGL Tutorial", NULL, NULL);
    if(!gWindow)
        throw std::runtime_error("glfwCreateWindow failed. Can your hardware handle OpenGL 3.2?");
    
    // GLFW settings
    glfwMakeContextCurrent(gWindow);
    
    // initialise GLEW
    glewExperimental = GL_TRUE; //stops glew crashing on OSX :-/
    if(glewInit() != GLEW_OK)
        throw std::runtime_error("glewInit failed");
    
    // print out some info about the graphics drivers
    std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    
    // make sure OpenGL version 3.2 API is available
    if(!GLEW_VERSION_3_2)
        throw std::runtime_error("OpenGL 3.2 API is not available.");
}
