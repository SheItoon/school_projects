/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Scene.cpp
*/

// @TODO check if Resources list is not empty

#include "scene/AScene.hpp"
#include "entity/Entity.hpp"
#include "factory/AFactory.hpp"

sw::Entity& sw::AScene::createEntity(const std::string& entityName)
{
    auto it = m_entityMap.find(entityName);

    if (it == m_entityMap.end()) {
        it = m_entityMap.try_emplace(entityName, std::make_unique<sw::Entity>(entityName, *this)).first;
    }
    return (static_cast<sw::Entity&>(*it->second));
}

sw::Entity& sw::AScene::getEntity(const std::string& entityName)
{
    auto it = m_entityMap.find(entityName);

    if (it == m_entityMap.end())
        throw sw::Error("ERROR: sw::Scene::getEntity - Can't find Entity", "");
    return (static_cast<sw::Entity&>(*it->second));
}