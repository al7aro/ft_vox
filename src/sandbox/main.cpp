#include <iostream>

#include <glm/glm.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../engine/ft_engine.hpp"

int main(void)
{
    if (!glfwInit())
        return (-1);    
    ft::Window win("ft_vox", 500, 500);
    auto wasd = std::make_shared<ft::KeyHandler>(std::vector<int>({ GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D }));
    auto arrows = std::make_shared<ft::KeyHandler>(std::vector<int>({GLFW_KEY_UP,GLFW_KEY_DOWN, GLFW_KEY_LEFT, GLFW_KEY_RIGHT}));
    auto mouse = std::make_shared<ft::MouseHandler>(std::vector<int>({GLFW_MOUSE_BUTTON_RIGHT, GLFW_MOUSE_BUTTON_LEFT}));
    win.AddListenTo(wasd);
    win.AddListenTo(arrows);
    win.AddListenTo(mouse);

    ft::FPSCamera cam;
    cam.SetPosition(glm::vec3(0.0, 0.0, 1.0));
    ft::ShaderSource sh_src = ft::read_shader_file(SANDBOX_DIRECTORY"/assets/basic.glsl");

    std::vector<ft::Vertex> trig = {
        {{-0.5, -0.5, 0.0}, {0.0, 0.0}, {1.0, 0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}},
        {{0.5, -0.5, 0.0},  {0.0, 0.0}, {0.0, 1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}},
        {{0.0, 0.5, 0.0},   {0.0, 0.0}, {0.0, 0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}},
    };

    ft::VAO vao;
    ft::VBO vbo(trig);
    vao.AddVBO(vbo);

    /* SHADERS */
    ft::Shader sh(sh_src);

    glClearColor(0.9, 0.1, 0.35, 1.0);
    while (!win.IsRunning())
    {
        win.PollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glm::vec2 cursor_pos = mouse->GetCursorPos();
        glm::vec2 scroll = mouse->GetScrollOffset();

        if (wasd->IsKeyDown(GLFW_KEY_W))
            cam.Move(glm::vec3(0.0, 0.0, -0.01));
        if (wasd->IsKeyDown(GLFW_KEY_S))
            cam.Move(glm::vec3(0.0, 0.0, 0.01));

        if (arrows->IsKeyDown(GLFW_KEY_LEFT))
            cam.Yaw(0.01);
        if (arrows->IsKeyDown(GLFW_KEY_RIGHT))
            cam.Yaw(-0.01);
        if (arrows->IsKeyDown(GLFW_KEY_UP))
            cam.Pitch(0.01);
        if (arrows->IsKeyDown(GLFW_KEY_DOWN))
            cam.Pitch(-0.01);

        sh.Bind();
        sh.SetUniform("u_proj", cam.GetProjectionMat());
        sh.SetUniform("u_view", cam.GetViewMat());
        vao.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);

        win.SwapBuffers();
    }
    win.Destroy();
    glfwTerminate();
    return (0);
}