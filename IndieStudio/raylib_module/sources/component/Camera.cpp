/*
** EPITECH PROJECT, 2021
** Camera.cpp
** File description:
** Camera.cpp
*/

#include "component/Camera.hpp"

ray::RCamera::RCamera(sw::Entity &entityRef) :
sw::Component(entityRef),
m_camera(),
m_projection(CAMERA_PERSPECTIVE),
m_fov(45),
m_up({0, 1, 0}),
m_target({-8, 0, 7})
{
    m_camera.position = {-8, 20, 23};
    m_camera.target = {m_target.x, m_target.y, m_target.z};
    m_camera.up = {m_up.x, m_up.y, m_up.z};
    m_camera.fovy = m_fov;
    m_camera.projection = m_projection;
}

ray::RCamera & ray::RCamera::setProjection(int projection)
{
    m_projection = projection;
    m_camera.projection = m_projection;
    return (*this);
}

ray::RCamera & ray::RCamera::setFOV(float fov)
{
    m_fov = fov;
    m_camera.fovy = m_fov;
    return (*this);
}

ray::RCamera& ray::RCamera::setUp(float x, float y, float z)
{
    m_up.y = y;
    m_up.x = x;
    m_up.z = z;
    return (*this);
}

ray::RCamera & ray::RCamera::setUp(const sw::Vector3<float>& vector)
{
    m_up = vector;
    return (*this);
}

ray::RCamera & ray::RCamera::setTarget(float x, float y, float z)
{
    m_target.x = x;
    m_target.y = y;
    m_target.z = z;
    return (*this);
}

ray::RCamera & ray::RCamera::setTarget(const sw::Vector3<float>& vector)
{
    m_target = vector;
    return (*this);
}

int ray::RCamera::getProjection() const
{
    return (m_projection);
}

float ray::RCamera::getFOV() const
{
    return (m_fov);
}

sw::Vector3<float> ray::RCamera::getTarget() const
{
    return (m_target);
}

sw::Vector3<float> ray::RCamera::getUp() const
{
    return (m_up);
}

Camera *ray::RCamera::getCamera()
{
    return (&m_camera);
}

ray::RCamera & ray::RCamera::setPosition(sw::Vector3f vector)
{
    m_camera.position.x = vector.x;
    m_camera.position.y = vector.y;
    m_camera.position.z = vector.z;
    return (*this);
}

ray::RCamera & ray::RCamera::setPosition(float x, float y, float z)
{
    m_camera.position.x = x;
    m_camera.position.y = y;
    m_camera.position.z = z;
    return (*this);
}