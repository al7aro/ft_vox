#pragma once

#include <string>
#include <vector>
#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "input/Input.hpp"
#include "input/MouseHandler.hpp"
#include "input/KeyHandler.hpp"

namespace ft {

    class Window
    {
    private:
        GLFWwindow* _win;
        std::string _title;
        int _width, _height;

        std::vector<std::shared_ptr<MouseHandler> > _mouse_handlers;
        std::vector<std::shared_ptr<KeyHandler> > _key_handlers;
    public:
        /* Requires a inited GLFW*/
        Window(const std::string& title, int width, int height);

        bool IsRunning() const;
        void PollEvents() const;
        void SwapBuffers() const;

        /* Does not terminate GLFW */
        void Destroy() const;

        /* INPUT */
        void AddListenTo(std::shared_ptr<MouseHandler> handler);
        void AddListenTo(std::shared_ptr<KeyHandler> handler);
        /* CALLBACKS */
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void cursor_callback(GLFWwindow* window, double xpos, double ypos);
        static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
    };

}