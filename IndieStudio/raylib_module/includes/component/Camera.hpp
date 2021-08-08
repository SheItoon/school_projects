/*
** EPITECH PROJECT, 2021
** Camera.hpp
** File description:
** Camera.hpp
*/

#ifndef CAMERA
#define CAMERA

#include "SW/Components.hpp"
#include "raylib.h"
#include "utils/vector3.hpp"

namespace ray
{
    class RCamera :
        public sw::Component
    {
    private:
        Camera m_camera;
        int m_projection;
        float m_fov;
        sw::Vector3<float> m_up;
        sw::Vector3<float> m_target;

    public:
        RCamera() = delete;
        ~RCamera() = default;
        explicit RCamera(sw::Entity &entityRef);

        RCamera& setProjection(int projection);
        RCamera& setFOV(float fov);
        RCamera& setUp(float x, float y, float z);
        RCamera& setUp(const sw::Vector3<float>& vector);
        RCamera& setTarget(float x, float y, float z);
        RCamera& setTarget(const sw::Vector3<float>& vector);
        RCamera& setPosition(sw::Vector3f vector);
        RCamera& setPosition(float x, float y, float z);

        [[nodiscard]]int getProjection() const;
        [[nodiscard]]float getFOV() const;
        [[nodiscard]]sw::Vector3<float> getUp() const;
        [[nodiscard]]sw::Vector3<float> getTarget() const;
        [[nodiscard]]Camera *getCamera();
    };
}

#endif //CAMERA
