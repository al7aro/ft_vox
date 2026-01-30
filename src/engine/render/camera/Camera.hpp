#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace ft {

    class Camera
    {
    protected:
        glm::vec3 _pos;
        glm::quat _rot;

        glm::vec3 _look_at_target;
        bool _look_at_enabled;

        float _aspect, _fov, _near, _far;
    public:
        Camera();
        ~Camera();

        void Move(const glm::vec3& offset);
        void SetPosition(const glm::vec3& pos);

        virtual void Pitch(float angle);
        virtual void Yaw(float angle);
        virtual void Roll(float angle);

        glm::mat4 GetViewMat() const;
        glm::mat4 GetProjectionMat() const;
    };

}