/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Cube.cpp
*/

#include "component/Collider.hpp"
#include "component/Transform.hpp"

ray::CubeCollider::CubeCollider(sw::Entity& entity)
    :   ray::Collider(entity),
        m_origin{0, 0, 0},
        m_size{10, 10, 10},
        m_cube{m_origin, m_size},
        m_meshRef{nullptr}
{
    m_type = CUBE;
}

ray::CubeCollider::CubeCollider(sw::Entity& entity, const Vector3& size)
    :   ray::Collider(entity),
        m_origin{0, 0, 0},
        m_size{size},
        m_cube{m_origin, m_size},
        m_meshRef{nullptr}
{
    m_type = CUBE;
}

ray::CubeCollider::CubeCollider(sw::Entity& entity, const Vector3& origin, const Vector3& size)
    :   ray::Collider(entity),
        m_origin{origin},
        m_size{size},
        m_cube{m_origin, m_size},
        m_meshRef{nullptr}
{
    m_type = CUBE;
}

BoundingBox ray::CubeCollider::cube()
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
        return (m_cube);

    sw::Vector3f tmpPosMin;
    sw::Vector3f tmpPosMax;
    if (m_meshRef != nullptr) {
        BoundingBox cube = GetMeshBoundingBox(*(*m_meshRef));
        tmpPosMin = {cube.min.x,
                     cube.min.y,
                     cube.min.z};
        tmpPosMax = {cube.max.x,
                     cube.max.y,
                     cube.max.z};
    } else {
        tmpPosMin = {m_origin.x, m_origin.y, m_origin.z};
        tmpPosMax = {m_origin.x + m_size.x, m_origin.y + m_size.y, m_origin.z + m_size.z};
    }

    Vector3 posMin{(tmpPosMin.x * scl.x) + pos.x,
                   (tmpPosMin.y * scl.y) + pos.y,
                   (tmpPosMin.z * scl.z) + pos.z};
    Vector3 posMax{(tmpPosMax.x * scl.x) + pos.x,
                   (tmpPosMax.y * scl.y) + pos.y,
                   (tmpPosMax.z * scl.z) + pos.z};

    m_cube = {posMin, posMax};
    m_needUpdate = false;
    return (m_cube);
}

void ray::CubeCollider::setOrigin(const Vector3& origin)
{
    m_origin = origin;
    m_needUpdate = true;
}

void ray::CubeCollider::setSize(const Vector3& size)
{
    m_size = size;
    m_needUpdate = true;
}

void ray::CubeCollider::setMeshReference(::Mesh* mesh)
{
    m_meshRef = std::make_shared<::Mesh*>(mesh);
}

void ray::CubeCollider::draw(Color color)
{
    DrawBoundingBox(cube(), color);
}