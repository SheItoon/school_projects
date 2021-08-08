/*
** EPITECH PROJECT, 2021
** translate.cpp
** File description:
** translate.cpp
*/

#include "component/Transform.hpp"

void ray::Transform::setPosition(const sw::Vector3f& position)
{
    move(position - m_position);
}

void ray::Transform::setPosition(float x, float y, float z)
{
    move({x - m_position.x, y - m_position.y, z - m_position.z});
}

void ray::Transform::move(const sw::Vector3f& position)
{
    if (position.x != 0 || position.y != 0 || position.z != 0) {
        m_position += position;
        m_globalPosition += position;
        for (auto& [_, entity] : m_entity.m_childrenMap)
            entity.get().getComponent<ray::Transform>("TransformFact").move(position);
        needUpdate();
    }
}

void ray::Transform::move(float x, float y, float z)
{
    move({x, y, z});
}

const sw::Vector3f& ray::Transform::getPosition() const
{
    return (m_position);
}

const sw::Vector3f& ray::Transform::getGlobalPosition() const
{
    return (m_globalPosition);
}