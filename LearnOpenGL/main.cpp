#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Cube.h"
#include "Input.h"
#include "Rect.h"
#include "Shader.h"
#include "Texture.h"
#include <array>

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
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
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

    Rect rect = Rect();
    rect.setup();

    std::array<Cube, 3> cubes{};
    for (unsigned int i = 0; i < cubes.size(); i++)
    {
        std::cout << "Start cube " << i << std::endl;
        // --- Doing it this way will not work for some reason ---
        // Cube cube = Cube();
        // cube.setup();
        // cubes[i] = cube;
        // -------------------------------------------------------
        cubes[i] = Cube();
        cubes[i].setup();
    }

    std::cout << "After cube setup" << std::endl;

    Texture texture = Texture("container.jpg");
    Texture texture2 = Texture("book_img.jpg");

    // Shader shader("res/Basic.shader");
    Shader shader("res/BasicNoColor.shader");
    shader.Use();
    shader.SetInt("texture", 0);
    shader.SetInt("texture2", 1);

    while (!glfwWindowShouldClose(window))
    {
        input::processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (unsigned int i = 0; i < cubes.size(); i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(0.5f * (float)i, 0.5f * (float)i, 0.5f * (float)i));

            model = glm::rotate(model, (float)glfwGetTime(), glm::vec3(1.0f, 1.0f, 0.5f));
            unsigned int modelLoc = glGetUniformLocation(shader.ID, "model");
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

            glm::mat4 view = glm::mat4(1.0f);
            view = glm::translate(view, glm::vec3(0.0f, 0.0f, -5.0f));
            unsigned int viewLoc = glGetUniformLocation(shader.ID, "view");
            glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

            glm::mat4 projection = glm::mat4(1.0f);
            projection = glm::perspective(glm::radians(100.0f), 800.0f / 600.0f, 0.1f, 100.0f);
            unsigned int projectionLoc = glGetUniformLocation(shader.ID, "projection");
            glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture.m_ID);
            glActiveTexture(GL_TEXTURE1);
            glBindTexture(GL_TEXTURE_2D, texture2.m_ID);
            shader.Use();

            cubes[i].render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
