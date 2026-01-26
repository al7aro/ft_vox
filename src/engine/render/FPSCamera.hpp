#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/ext/matrix_transform.hpp>

#include "Camera.hpp"

namespace ft {

    class FPSCamera : public Camera
    {
    private:
        float _yaw, _pitch;

    public:
        FPSCamera();
        ~FPSCamera();

        void Pitch(float angle);
        void Yaw(float angle);
        void Roll(float angle);
    private:
        void UpdateRotation();
    };

}