#include "FPSCamera.hpp"

namespace ft {

    FPSCamera::FPSCamera()
        : Camera(), _yaw(0.0), _pitch(0.0)
    {

    }

    FPSCamera::~FPSCamera() {}

    void FPSCamera::Pitch(float angle)
    {
        _pitch += angle;
        UpdateRotation();
    }
    void FPSCamera::Yaw(float angle)
    {
        _yaw += angle;
        UpdateRotation();
    }
    void FPSCamera::Roll(float angle)
    {
    }

    void FPSCamera::UpdateRotation()
    {
        glm::quat q_yaw = glm::angleAxis(_yaw, glm::vec3(0.0, 1.0, 0.0));
        glm::quat q_pitch = glm::angleAxis(_pitch, glm::vec3(1.0, 0.0, 0.0));
        _rot = q_yaw * q_pitch;
    }

}