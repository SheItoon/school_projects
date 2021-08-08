/*
** EPITECH PROJECT, 2021
** TextFact.cpp
** File description:
** TextFact.cpp
*/

#include <string>

#include "component/Text.hpp"
#include "component/Transform.hpp"
#include "factory/TextFact.hpp"
#include "factory/TransformFact.hpp"

void ray::TextFact::onUpdate()
{
    std::string text;
    auto& fact = m_scene.getFactory<ray::TransformFact>("TransformFact");

    for (auto& [_, name] : m_componentLayer) {
        auto& obj = *m_componentMap[name];
        if (!obj.isActive() || !obj.m_entity.isActive())
            continue;
        auto& trans = fact[name];
        text = obj.getString().substr(0, obj.getNbrDisplayedChar());
        DrawTextEx(GetFontDefault(), text.c_str(), {trans.getPosition().x, trans.getPosition().y}, obj.getSize(), obj.getSpacing(), obj.getColor().getColor());
    }
}