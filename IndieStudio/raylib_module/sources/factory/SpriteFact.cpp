/*
** EPITECH PROJECT, 2021
** SpriteFact.cpp
** File description:
** SpriteFact.cpp
*/

#include "raylib.h"
#include "component/Sprite.hpp"
#include "component/Transform.hpp"
#include "factory/SpriteFact.hpp"
#include "factory/TransformFact.hpp"

void ray::SpriteFact::onUpdate()
{
    auto& sys = m_scene.getFactory<ray::TransformFact>("TransformFact");

    for (auto& [_, entityName] : m_componentLayer) {
        auto& obj = *m_componentMap[entityName];
        if (!obj.isActive() || !obj.m_entity.isActive())
            continue;
        auto& trans = sys[entityName];
        DrawTextureEx(*obj.texture(),
                      {trans.getPosition().x, trans.getPosition().y},
                      trans.getRotation().x,
                      trans.getScale().x,
                      obj.color().getColor());
    }
}