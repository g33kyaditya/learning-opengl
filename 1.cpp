#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

void key_callback(GLFWwindow*, int, int, int, int);

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpengL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Window not created\n";
        glfwTerminate();
    }
    else {
        std::cout << "The Window is created\n";
        glfwMakeContextCurrent(window);
    }

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std:: cout << "Failed to Initialize GLEW. Lol \n";
    }
    glViewport(0,0,800,600);
    glfwSetKeyCallback(window, key_callback);

    while(!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
        glfwTerminate();
    }
}
