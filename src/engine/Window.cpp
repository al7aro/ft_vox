#include "Window.hpp"

namespace ft {

    Window::Window(const std::string& title, int width, int height)
        : _title(title), _width(width), _height(height)
    {
        _win = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
        if (!_win)
            return ;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwMakeContextCurrent(_win);
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            glfwDestroyWindow(_win);
            _win = nullptr;
        }

        /* SET CALLBACKS */
        glfwSetWindowUserPointer(_win, this);
        glfwSetKeyCallback(_win, key_callback);
        glfwSetCursorPosCallback(_win, cursor_callback);
        glfwSetScrollCallback(_win, scroll_callback);
        glfwSetMouseButtonCallback(_win, mouse_button_callback);
    }

    bool Window::IsRunning() const
    {
        if (!_win) return (false);
        return (glfwWindowShouldClose(_win));
    }
    void Window::PollEvents() const
    {
        glfwPollEvents();
    }
    void Window::SwapBuffers() const
    {
        glfwSwapBuffers(_win);
    }

    void Window::Destroy() const
    {
        glfwDestroyWindow(_win);
    }

    /* INPUT */
    void Window::AddListenTo(MouseHandler* handler)
    {
        _mouse_handlers.push_back(handler);
    }
    void Window::AddListenTo(KeyHandler* handler)
    {
        _key_handlers.push_back(handler);
    }

    /* CALLBACKS */
    void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (!w)
            return ;
        for (KeyHandler* h : w->_key_handlers)
            h->UpdateState(key, scancode, action, mods);
    }
    void Window::cursor_callback(GLFWwindow* window, double xpos, double ypos)
    {
        Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (!w)
            return ;
        for (MouseHandler* h : w->_mouse_handlers)
            h->UpdateCursorState(xpos, ypos);
    }
    
    void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
    {
        Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (!w)
            return ;
        for (MouseHandler* h : w->_mouse_handlers)
            h->UpdateScrollState(xoffset, yoffset);
    }

    void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
    {
        Window* w = reinterpret_cast<Window*>(glfwGetWindowUserPointer(window));
        if (!w)
            return ;
        for (MouseHandler* h : w->_mouse_handlers)
            h->UpdateButtonState(button, action, mods);
    }

}