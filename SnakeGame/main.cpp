#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <array>
#include "Camera.h"
#include "Player.h"
#include "Consumable.h"
#include "Input.h"
#include "Rect.h"
#include "Shader.h"
#include "Texture.h"
#include "Scene.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Window initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(800, 600, "Mr. Snakey", NULL, NULL);
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
    glViewport(0, 0, 800, 600);
    // -------------------------------------------------------------------------

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glEnable(GL_DEPTH_TEST);

    Camera camera(glm::vec3(0.0f, 0.0f, 10.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(0.0f, 0.0f, -1.0f));
    Scene scene(camera);

    Player player{scene.world};
    scene.AddGameObject(player);

    Consumable apple{"tex/apple.jpg", "Apple"};
    apple.pos.x = 5;
    apple.pos.y = 5;
    scene.AddGameObject(apple);

    Consumable apple2{"tex/apple.jpg", "Apple2"};
    apple2.pos.x = 5;
    apple2.pos.y = 8;
    scene.AddGameObject(apple2);

    Consumable banana{"tex/banana.jpg", "Banana"};
    banana.pos.x = -5;
    banana.pos.y = 5;
    scene.AddGameObject(banana);

    float dt{0.0f};
    float last_frame{0.0f};
    float current_frame{0.0f};

    while (!glfwWindowShouldClose(window))
    {
        current_frame = glfwGetTime();
        dt = current_frame - last_frame;
        last_frame = current_frame;
        input::processInput(window, player, dt);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        scene.Render(dt);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
