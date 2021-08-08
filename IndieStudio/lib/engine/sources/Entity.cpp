/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Entity.cpp
*/

#include "entity/Entity.hpp"
#include "component/Component.hpp"

void sw::Entity::deleteComponent(const std::string& factoryName)
{
    return (m_scene.getFactory<sw::AFactory<sw::Component>>(factoryName).deleteComponent(m_name));
}

void sw::Entity::setLayer(const std::string& factoryName, int layer)
{
    return (m_scene.getFactory<sw::AFactory<sw::Component>>(factoryName).setLayer(m_name, layer));
}
