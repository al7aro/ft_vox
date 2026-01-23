#include "Input.hpp"

namespace ft{

    InputHandler::InputHandler(bool state)
        : _is_active(state)
    {
    }

    InputHandler::~InputHandler()
    {
    }

    const bool InputHandler::GetIsActive() const
    {
        return (_is_active);
    }

    void InputHandler::SetIsActive(bool active = true)
    {
        _is_active = active;
    }

}