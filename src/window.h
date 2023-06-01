#include<iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
    public:
    GLFWwindow* window;
    Window(const char* name,unsigned int hight,unsigned int width)
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        
        window = glfwCreateWindow(hight, width, name, NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Window: Failed to create GLFW window." << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        //glfwSetKeyCallback(window, key_callback);
        glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){glViewport(0, 0, width, height);});
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){std::cout << "Failed to initialize GLAD" << std::endl;}
        glfwSwapInterval(1);   
    }
    void Update()
    {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    

    glfwSwapBuffers(window);
    glfwPollEvents();
    } 
    bool are_not_closed(){return !glfwWindowShouldClose(window);}
    
    ~Window(void)
    {
        glfwTerminate();
        glfwDestroyWindow(window);
    }
    private:

};