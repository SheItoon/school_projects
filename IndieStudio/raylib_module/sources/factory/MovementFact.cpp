/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** MovementFact.cpp
*/

#include "component/Transform.hpp"
#include "factory/TransformFact.hpp"
#include "component/Movement.hpp"
#include "factory/MovementFact.hpp"

void ray::MovementFact::onUpdate()
{
    auto& tfmFact = m_scene.getFactory<ray::TransformFact>("TransformFact");

    for (auto& [_, name] : m_componentLayer) {
        auto& obj = *m_componentMap[name];
        auto& tfm = tfmFact[name];
        tfm.move(obj.x, obj.y, obj.z);
    }
}