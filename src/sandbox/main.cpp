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
    ft::KeyHandler wasd({GLFW_KEY_W, GLFW_KEY_A, GLFW_KEY_S, GLFW_KEY_D});
    ft::MouseHandler mouse({GLFW_MOUSE_BUTTON_RIGHT, GLFW_MOUSE_BUTTON_LEFT});

    win.AddListenTo(&wasd);
    win.AddListenTo(&mouse);

    glClearColor(0.9, 0.1, 0.35, 1.0);
    while (!win.IsRunning())
    {
        win.PollEvents();

        glClear(GL_COLOR_BUFFER_BIT);
        glm::vec2 cursor_pos = mouse.GetCursorPos();
        glm::vec2 scroll = mouse.GetScrollOffset();

        // std::cout << "CURSOR: [" << cursor_pos.x << ", " << cursor_pos.y << "]\n";
        // std::cout << "SCROLL: [" << scroll.x << ", " << scroll.y << "]\n";
        // if (wasd.IsKeyDown(GLFW_KEY_W))
        //     std::cout << "W\n";
        // if (wasd.IsKeyDown(GLFW_KEY_A))
        //     std::cout << "A\n";
        // if (wasd.IsKeyDown(GLFW_KEY_S))
        //     std::cout << "S\n";
        // if (wasd.IsKeyDown(GLFW_KEY_D))
        //     std::cout << "D\n";
        // if (mouse.IsButtonDown(GLFW_MOUSE_BUTTON_RIGHT))
        //     std::cout << "RIGHT BUTTON\n";
        // if (mouse.IsButtonDown(GLFW_MOUSE_BUTTON_LEFT))
        //     std::cout << "LEFT BUTTON\n";

        win.SwapBuffers();
    }
    win.Destroy();
    glfwTerminate();
    return (0);
}