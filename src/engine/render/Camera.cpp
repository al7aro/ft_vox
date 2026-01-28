#include "Camera.hpp"

namespace ft {

    Camera::Camera()
        : _pos(0.0), _rot(1.0, 0.0, 0.0, 0.0), _look_at_target(0.0), _look_at_enabled(false),
        _aspect(1.0), _fov(glm::radians(100.0f)), _near(0.1), _far(100.0)
    {

    }

    Camera::~Camera() {}

    void Camera::Move(const glm::vec3& offset)
    {
        _pos += _rot * offset;
    }
    void Camera::SetPosition(const glm::vec3& pos)
    {
        _pos = pos;
    }

    void Camera::Pitch(float angle)
    {
        glm::quat q = glm::angleAxis(angle, glm::vec3(1.0, 0.0, 0.0));
        _rot = _rot * q;
    }
    void Camera::Yaw(float angle)
    {
        glm::quat q = glm::angleAxis(angle, glm::vec3(0.0, 1.0, 0.0));
        _rot = _rot * q;
    }
    void Camera::Roll(float angle)
    {
        glm::quat q = glm::angleAxis(angle, glm::vec3(0.0, 0.0, 1.0));
        _rot = _rot * q;
    }

    glm::mat4 Camera::GetViewMat() const
    {
        glm::mat4 tr = glm::translate(glm::mat4(1.0), -_pos);
        glm::mat4 rot = glm::mat4_cast(glm::inverse(_rot));
        return (rot * tr);
    }
    glm::mat4 Camera::GetProjectionMat() const
    {
        glm::mat4 proj = glm::perspective(_fov, _aspect, _near, _far);
        return (proj);
    }

}