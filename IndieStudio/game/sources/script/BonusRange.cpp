/*
** EPITECH PROJECT, 2021
** BonusRange.cpp
** File description:
** BonusRange.cpp
*/

#include "script/BonusRange.hpp"
#include "script/Player.hpp"
#include "component/components.hpp"
#include "factory/factories.hpp"
#include "Module.hpp"

static double easeInOutQuad( double t )
{
    return (t < 0.5 ? 2 * t * t : t * (4 - 2 * t) - 1);
}

static float make_blue(float red)
{
    if (red < 1.f)
        return red;
    return 2.f - red;
}

BonusRange::BonusRange(sw::Entity& entity) :
sw::Script(entity),
m_animTime(0.0f)
{}

BonusRange::~BonusRange() noexcept
{
    m_entity.m_scene.deleteEntity(m_entity.m_name);
}

void BonusRange::start()
{
    auto& transform = m_entity.createComponent<ray::Transform>("TransformFact");

    transform.setScale(0.5f, 0.5f, 0.5f);
    m_entity.createComponent<ray::Mesh>("MeshFact").setModel("BonusRange").setTexture("RangeIcon");
    m_entity.insertComponent<ray::Collider, ray::CubeCollider>("ColliderFact", Vector3{-0.50, -0.50, -0.50}, Vector3{1, 1, 1});
    m_entity.createComponent<ray::Audio>("AudioFact").addSound("Bonus1", "Bonus1").addSound("Bonus2", "Bonus2").addSound("Bonus3", "Bonus3").addSound("Bonus4", "Bonus4");
}

void BonusRange::update()
{
    auto& transform = m_entity.getComponent<ray::Transform>("TransformFact");
    float time = dynamic_cast<ray::Module&>(sw::Engine::activeModule()).getDeltaTime();

    m_animTime += time;
    while (m_animTime > 2.0f)
        m_animTime -= 2.0f;
    auto tmp = easeInOutQuad(make_blue(m_animTime));
    tmp -= 0.5f;
    transform.move(0, (float)tmp * 0.05f, 0);
    transform.rotate(70 * time);
}

void BonusRange ::onCollision(sw::Entity& entity)
{
    takeIt(entity);
}

void BonusRange::takeIt(sw::Entity& entity)
{
    auto& player = entity.getComponent<Player>("ScriptFact");

    player.setRange(player.getRange() + 1);
    destroy();
    m_entity.getComponent<ray::Audio>("AudioFact").play("Bonus" + std::to_string((std::rand() % 3) + 1));
}

void BonusRange::destroy()
{
    auto& transFact = m_entity.m_scene.getFactory<ray::TransformFact>("TransformFact");
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
    auto& colliderFact = m_entity.m_scene.getFactory<ray::ColliderFact>("ColliderFact");

    transFact.deleteComponent(m_entity.m_name);
    scriptFact.deleteComponent(m_entity.m_name);
    colliderFact.deleteComponent(m_entity.m_name);
    m_entity.getComponent<ray::Mesh>("MeshFact").setActive(false);
}