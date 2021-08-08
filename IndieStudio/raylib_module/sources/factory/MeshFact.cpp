/*
** EPITECH PROJECT, 2021
** MeshFact.cpp
** File description:
** MeshFact.cpp
*/

#include "component/Mesh.hpp"
#include "component/Camera.hpp"
#include "component/Transform.hpp"
#include "factory/MeshFact.hpp"
#include "factory/TransformFact.hpp"

void ray::MeshFact::onUpdate()
{
    auto& sys = m_scene.getFactory<ray::TransformFact>("TransformFact");
    auto& camera = m_scene.getEntity("MainCamera").getComponent<ray::RCamera>("CameraFact");

    BeginMode3D(*camera.getCamera());
    for (auto& [_, entityName] : m_componentLayer) {
        auto& obj = *m_componentMap[entityName];
        if (!obj.isActive() || !obj.m_entity.isActive())
            continue;
        auto& trans = sys[entityName];
        if (obj.hasAnimation()) {
            obj.increaseAnimCount();
            UpdateModelAnimation(obj.getModel(), obj.getAnimator()[0], obj.getAnimCount());
            if (obj.getAnimCount() >= obj.getAnimator()[0].frameCount)
                obj.setAnimCount(0);
        }
        DrawModelEx(obj.getModel(),
                    {trans.getPosition().x, trans.getPosition().y, trans.getPosition().z},
                    {trans.getRotation().x, trans.getRotation().y, trans.getRotation().z},
                    trans.getAngle(),
                    {trans.getScale().x, trans.getScale().y, trans.getScale().z},
                    obj.getColor().getColor());
    }
    EndMode3D();
}