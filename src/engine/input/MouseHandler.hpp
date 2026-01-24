#pragma once

#include <glm/glm.hpp>

#include "Input.hpp"

namespace ft {

    /* ************************ */
    /*          TODO:           */
    /* - Store cursor speed     */
    /* - Store cursor direction */
    /* ************************ */
    class MouseHandler : public InputHandler
    {
    private:
        glm::vec2 _pos;
        glm::vec2 _prev_pos;
        glm::vec2 _scroll_offset;
        std::map<int, bool> _active_buttons;

    public:
        MouseHandler();
        MouseHandler(const std::vector<int>& active_buttons);
        ~MouseHandler();

        void UpdateCursorState(double xpos, double ypos);
        void UpdateScrollState(double xoffset, double yoffset);
        void UpdateButtonState(int button, int action, int mods);

        const glm::vec2 GetCursorPos() const;
        const glm::vec2 GetCursorPrevPos() const;
        const glm::vec2 GetScrollOffset() const;
        const bool IsButtonDown(int button) const;
    };

}