/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Sphere.cpp
*/

#include "component/Collider.hpp"
#include "component/Transform.hpp"

ray::SphereCollider::SphereCollider(sw::Entity& entity)
    :   ray::Collider(entity),
        m_origin{0, 0, 0},
        m_realOrigin{m_origin},
        m_radius{10},
        m_realRadius{m_radius}
{
    m_type = SPHERE;
}

ray::SphereCollider::SphereCollider(sw::Entity& entity, float radius)
    :   ray::Collider(entity),
        m_origin{0, 0, 0},
        m_realOrigin{m_origin},
        m_radius{radius},
        m_realRadius{m_radius}
{
    m_type = SPHERE;
}

ray::SphereCollider::SphereCollider(sw::Entity& entity, const Vector3& origin, float radius)
    :   ray::Collider(entity),
        m_origin{origin},
        m_realOrigin{m_origin},
        m_radius{radius},
        m_realRadius{m_radius}
{
    m_type = SPHERE;
}

void ray::SphereCollider::setOrigin(const Vector3& origin)
{
    m_origin = origin;
}

void ray::SphereCollider::setRadius(float radius)
{
    m_radius = radius;
}

Vector3 ray::SphereCollider::origin()
{
    sw::Vector3f pos{0, 0, 0};
    sw::Vector3f scl{1, 1, 1};
    bool tfmNeedUpdate = false;
    try {
        auto& tfm = m_entity.getComponent<ray::Transform>("TransformFact");
        tfmNeedUpdate = tfm.checkUpdate();
        pos = tfm.getPosition();
        scl = tfm.getScale();
    } catch (std::exception) {};
    if (!m_needUpdate && !tfmNeedUpdate)
        return (m_realOrigin);

    m_realOrigin = {(m_origin.x * scl.x) + pos.x,
                    (m_origin.y * scl.y) + pos.y,
                    (m_origin.z * scl.z) + pos.z};
    m_needUpdate = false;
    return (m_realOrigin);
}

float ray::SphereCollider::radius()
{
    sw::Vector3f pos{0, 0, 0};
    sw::Vector3f scl{1, 1, 1};
    bool tfmNeedUpdate = false;
    try {
        auto& tfm = m_entity.getComponent<ray::Transform>("TransformFact");
        tfmNeedUpdate = tfm.checkUpdate();
        pos = tfm.getPosition();
        scl = tfm.getScale();
    } catch (std::exception) {};
    if (!m_needUpdate && !tfmNeedUpdate)
        return (m_realRadius);

    m_realRadius = m_radius * scl.x;
    m_needUpdate = false;
    return (m_realRadius);
}

void ray::SphereCollider::draw(Color color)
{
    DrawSphere(origin(), radius(), color);
}
