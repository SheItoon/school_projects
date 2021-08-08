/*
** EPITECH PROJECT, 2021
** rotate.cpp
** File description:
** rotate.cpp
*/

#include <cmath>

#include "component/Transform.hpp"

void ray::Transform::setRotation(float angle, float rotationX, float rotationY, float rotationZ)
{
    if (rotationX != 0 || rotationY != 0 || rotationZ != 0 || angle != 0) {
        m_angle = angle;
        m_rotation.x = rotationX;
        m_rotation.y = rotationY;
        m_rotation.z = rotationZ;
        m_globalRotation.x = rotationX;
        m_globalRotation.y = rotationY;
        m_globalRotation.z = rotationZ;
        for (auto& [_, entity] : m_entity.m_childrenMap)
            entity.get().getComponent<ray::Transform>("TransformFact").setRotation(rotationX, rotationY, rotationZ);
        needUpdate();
    }}

void ray::Transform::rotate(float angle, float rotationX, float rotationY, float rotationZ)
{
    if (rotationX != 0 || rotationY != 0 || rotationZ != 0 || angle != 0) {
        m_angle += angle;
        m_rotation.x += rotationX;
        m_rotation.y += rotationY;
        m_rotation.z += rotationZ;
        m_globalRotation.x += rotationX;
        m_globalRotation.y += rotationY;
        m_globalRotation.z += rotationZ;
        for (auto& [_, entity] : m_entity.m_childrenMap)
            entity.get().getComponent<ray::Transform>("TransformFact").rotate(rotationX, rotationY, rotationZ);
        needUpdate();
    }
}

sw::Vector3f ray::Transform::getRotation() const
{
    return (m_rotation);
}

float ray::Transform::getAngle() const
{
    return (m_angle);
}

sw::Vector3f ray::Transform::getRadianRotation() const
{
    return (m_rotation * (3.14f / 180));
}

sw::Vector3f ray::Transform::getGlobalRotation() const
{
    return (m_globalRotation);
}

sw::Vector3f ray::Transform::getGlobalRadianRotation() const
{
    return (m_globalRotation * (3.14f / 180));
}