#include "MouseHandler.hpp"

namespace ft {

    MouseHandler::MouseHandler()
        : InputHandler(true), _pos(0.0, 0.0), _prev_pos(0.0, 0.0)
    {
    }

    MouseHandler::MouseHandler(const std::vector<int>& active_buttons)
        : InputHandler(true)
    {
        for (int key : active_buttons)
            _active_buttons[key] = false;
    }

    MouseHandler::~MouseHandler()
    {}

    void MouseHandler::UpdateCursorState(double xpos, double ypos)
    {
        _prev_pos.x = _pos.x;
        _prev_pos.y = _pos.y;
        _pos.x = static_cast<float>(xpos);
        _pos.y = static_cast<float>(ypos);
    }

    void MouseHandler::UpdateScrollState(double xoffset, double yoffset)
    {
        _scroll_offset.x = static_cast<float>(xoffset);
        _scroll_offset.y = static_cast<float>(yoffset);
    }

    void MouseHandler::UpdateButtonState(int button, int action, int mods)
    {
        std::map<int, bool>::iterator it = _active_buttons.find(button);
        if (it != _active_buttons.end())
            it->second = (action != GLFW_RELEASE);
    }

    const glm::vec2 MouseHandler::GetCursorPos() const
    {
        return (_pos);
    }

    const glm::vec2 MouseHandler::GetCursorPrevPos() const
    {
        return (_prev_pos);
    }

    const glm::vec2 MouseHandler::GetScrollOffset() const
    {
        return (_scroll_offset);
    }

    const bool MouseHandler::IsButtonDown(int button) const
    {
        if (!_is_active)
            return false;
        std::map<int, bool>::const_iterator it = _active_buttons.find(button);
        if (it != _active_buttons.end())
            return (it->second);
        return (false);
    }


}