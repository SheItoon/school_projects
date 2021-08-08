/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Collider.cpp
*/

#include "component/Collider.hpp"

ray::Collider::Collider(sw::Entity& entity)
    :   sw::Component(entity),
        m_type(UNDEFINED),
        m_needUpdate(true)
{}

bool ray::CubeCollider::collide(ray::Collider& collider)
{
    bool result = false;

    if (collider.type() == ray::Collider::CUBE) {
        auto& otherCube = static_cast<ray::CubeCollider&>(collider);
        result = CheckCollisionBoxes(cube(), otherCube.cube());
    }
    else if (collider.type() == ray::Collider::SPHERE) {
        auto &sphere = static_cast<ray::SphereCollider&>(collider);
        result = CheckCollisionBoxSphere(cube(), sphere.origin(), sphere.radius());
    }
    else if (collider.type() == ray::Collider::RAY) {
        auto &ray = static_cast<ray::RayCollider&>(collider);
        result = GetRayCollisionBox(ray.ray(), cube()).hit;
    }
    return (result);
}

bool ray::SphereCollider::collide(ray::Collider& collider)
{
    bool result = false;

    if (collider.type() == ray::Collider::CUBE) {
        auto& cube = static_cast<ray::CubeCollider&>(collider);
        result = CheckCollisionBoxSphere(cube.cube(), origin(), radius());
    }
    else if (collider.type() == ray::Collider::SPHERE) {
        auto &sphere = static_cast<ray::SphereCollider&>(collider);
        result = CheckCollisionSpheres(origin(), radius(), sphere.origin(), sphere.radius());
    }
    else if (collider.type() == ray::Collider::RAY) {
        auto &ray = static_cast<ray::RayCollider&>(collider);
        result = GetRayCollisionSphere(ray.ray(), origin(), radius()).hit;
    }
    return (result);
}

bool ray::RayCollider::collide(ray::Collider& collider)
{
    bool result = false;

    if (collider.type() == ray::Collider::CUBE) {
        auto& cube = static_cast<ray::CubeCollider&>(collider);
        result = GetRayCollisionBox(ray(), cube.cube()).hit;
    }
    else if (collider.type() == ray::Collider::SPHERE) {
        auto &sphere = static_cast<ray::SphereCollider&>(collider);
        result = GetRayCollisionSphere(ray(), sphere.origin(), sphere.radius()).hit;
    }
    return (result);
}

ray::RayCollider::CollisionInfo ray::RayCollider::collideWInfo(Collider& collider)
{
    ray::RayCollider::CollisionInfo result;

    if (collider.type() == ray::Collider::CUBE) {
        auto& cube = static_cast<ray::CubeCollider&>(collider);
        result = GetRayCollisionBox(ray(), cube.cube());
    }
    else if (collider.type() == ray::Collider::SPHERE) {
        auto &sphere = static_cast<ray::SphereCollider&>(collider);
        result = GetRayCollisionSphere(ray(), sphere.origin(), sphere.radius());
    }
    return (result);
}
