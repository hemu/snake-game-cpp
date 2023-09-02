#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <array>
#include "Camera.h"
#include "Player.h"
#include "Input.h"
#include "Shader.h"
#include "Texture.h"
#include "Scene.h"
#include "World.h"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void GameLoop(GLFWwindow *window)
{
    Camera camera(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    Player player{};
    Scene scene(camera, player);
    scene.Setup();

    float dt{0.0f};
    float last_frame{0.0f};
    float current_frame{0.0f};
    while (!glfwWindowShouldClose(window))
    {
        current_frame = static_cast<float>(glfwGetTime());
        dt = current_frame - last_frame;
        last_frame = current_frame;
        input::processInput(window, player, dt);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene.Update(dt);
        scene.Render(dt, current_frame);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main()
{
    // -------------------- Create Window ------------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Mr. Snakey", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    // -------------------------------------------------------------------------
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glEnable(GL_DEPTH_TEST);
    // Enable transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GameLoop(window);

    glfwTerminate();
    return 0;
}
