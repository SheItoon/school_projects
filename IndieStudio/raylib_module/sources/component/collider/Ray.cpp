/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Ray.cpp
*/

#include "component/Collider.hpp"
#include "component/Transform.hpp"

ray::RayCollider::RayCollider(sw::Entity& entity)
    :   ray::Collider(entity),
        m_origin{0, 0, 0},
        m_direction{0, 0, 0},
        m_ray{m_origin, m_direction}
{
    m_type = RAY;
}

ray::RayCollider::RayCollider(sw::Entity& entity, const Vector3& direction)
    :   ray::Collider(entity),
        m_origin{0, 0, 0},
        m_direction{direction},
        m_ray{m_origin, m_direction}
{
    m_type = RAY;
}

ray::RayCollider::RayCollider(sw::Entity& entity, const Vector3& origin, const Vector3& direction)
    :   ray::Collider(entity),
        m_origin{origin},
        m_direction{direction},
        m_ray{m_origin, m_direction}
{
    m_type = RAY;
}

void ray::RayCollider::setOrigin(const Vector3& origin)
{
    m_origin = origin;
}

void ray::RayCollider::setDirection(const Vector3& direction)
{
    m_direction = direction;
}

Ray ray::RayCollider::ray()
{
    sw::Vector3f pos{0, 0, 0};
    sw::Vector3f scl{1, 1, 1};
    float angle = 0;
    bool tfmNeedUpdate = false;
    try {
        auto& tfm = m_entity.getComponent<ray::Transform>("TransformFact");
        tfmNeedUpdate = tfm.checkUpdate();
        pos = tfm.getPosition();
        scl = tfm.getScale();
        angle = tfm.getAngle();
    } catch (std::exception) {};
    if (!m_needUpdate && !tfmNeedUpdate)
        return (m_ray);

    Vector3 origin{(m_origin.x * scl.x) + pos.x,
                   (m_origin.y * scl.y) + pos.y,
                   (m_origin.z * scl.z) + pos.z};

    m_ray = {origin, m_direction};
    m_needUpdate = false;
    return (m_ray);
}

void ray::RayCollider::draw(Color color)
{
    DrawRay(ray(), color);
}