/*
** EPITECH PROJECT, 2021
** scale.cpp
** File description:
** scale.cpp
*/

#include "component/Transform.hpp"

void ray::Transform::setScale(const sw::Vector3f& value)
{
    scale(value / m_scale);
}

void ray::Transform::setScale(float x, float y, float z)
{
    m_scale.x = x;
    m_scale.y = y;
    m_scale.z = z;
}

void ray::Transform::scale(const sw::Vector3f& scale)
{
    if (scale.x != 0 || scale.y != 0 || scale.z != 0) {
        m_scale *= scale;
        m_globalScale *= scale;
        for (auto& [_, entity] : m_entity.m_childrenMap)
            entity.get().getComponent<ray::Transform>("TransformFact").scale(scale);
        needUpdate();
    }
}

void ray::Transform::scale(float x, float y, float z)
{
    scale({x, y, z});
}

const sw::Vector3f& ray::Transform::getScale() const
{
    return (m_scale);
}

const sw::Vector3f& ray::Transform::getGlobalScale() const
{
    return (m_globalScale);
}