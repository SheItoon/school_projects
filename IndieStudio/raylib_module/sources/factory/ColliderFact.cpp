/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ColliderFact.cpp
*/

#include "component/Collider.hpp"
#include "component/Camera.hpp"
#include "factory/ColliderFact.hpp"
#include "Module.hpp"

#include <iostream>

void ray::ColliderFact::onUpdate()
{
    if (!m_isActive)
        return;

    auto& camera = m_scene.getEntity("MainCamera").getComponent<ray::RCamera>("CameraFact");

    BeginMode3D(*camera.getCamera());
    for (auto& [_, name] : m_componentLayer) {
        auto& cpt = *m_componentMap[name];
        if (!cpt.isActive() || !sw::Engine::getModule<ray::Module>("RayLib").isDebuging())
            continue;
        cpt.draw({100, 255, 0, 255});
    }
    EndMode3D();
}
