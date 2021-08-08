/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** Fire
*/

#include "script/Fire.hpp"
#include "component/components.hpp"
#include "script/MapGenerator.hpp"
#include "factory/factories.hpp"


Fire::Fire(sw::Entity &entity, sw::Vector2i pos_fire) :
sw::Script(entity), m_chrono(), m_pos(pos_fire)
{
}

Fire::~Fire() noexcept
{
    m_entity.m_scene.deleteEntity(m_entity.m_name);
}

void Fire::start()
{
    
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");
    trans.setPosition(sw::Vector3f{static_cast<float>(m_pos.x * -1), 0, static_cast<float>(m_pos.y)});
    m_entity.createComponent<ray::Mesh>("MeshFact").setModel("Fire").setTexture("Fire");

    trans.setScale(4, 4, 4);
    
}

void Fire::destroy()
{
    auto& transFact = m_entity.m_scene.getFactory<ray::TransformFact>("TransformFact");
    auto& meshFact = m_entity.m_scene.getFactory<ray::MeshFact>("MeshFact");
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");

    transFact.deleteComponent(m_entity.m_name);
    meshFact.deleteComponent(m_entity.m_name);
    scriptFact.deleteComponent(m_entity.m_name);
}

void Fire::update()
{
    auto& trans = m_entity.getComponent<ray::Mesh>("MeshFact");

    if (!m_chrono.isRunning())
        m_chrono = sw::Chrono(sw::Chrono::Lauch);
    if (m_chrono.getTotalTime() >= 1)
        destroy();
}