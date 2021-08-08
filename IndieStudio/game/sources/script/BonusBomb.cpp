/*
** EPITECH PROJECT, 2021
** BonusBomb.cpp
** File description:
** BonusBomb.cpp
*/

#include "script/BonusBomb.hpp"
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

BonusBomb::BonusBomb(sw::Entity& entity) :
sw::Script(entity),
m_animTime(0.0f)
{}

BonusBomb::~BonusBomb() noexcept
{
    m_entity.m_scene.deleteEntity(m_entity.m_name);
}

void BonusBomb::start()
{
    auto& transform = m_entity.createComponent<ray::Transform>("TransformFact");

    transform.setScale(0.5f, 0.5f, 0.5f);
    m_entity.createComponent<ray::Mesh>("MeshFact").setModel("BonusBomb").setTexture("BombIcon");
    m_entity.insertComponent<ray::Collider, ray::CubeCollider>("ColliderFact", Vector3{-0.50, -0.50, -0.50}, Vector3{1, 1, 1});
    m_entity.createComponent<ray::Audio>("AudioFact").addSound("Bonus1", "Bonus1").addSound("Bonus2", "Bonus2").addSound("Bonus3", "Bonus3").addSound("Bonus4", "Bonus4");
}

void BonusBomb::update()
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

void BonusBomb::onCollision(sw::Entity& entity)
{
    takeIt(entity);
}

void BonusBomb::destroy()
{
    auto& transFact = m_entity.m_scene.getFactory<ray::TransformFact>("TransformFact");
    auto& scriptFact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
    auto& colliderFact = m_entity.m_scene.getFactory<ray::ColliderFact>("ColliderFact");

    transFact.deleteComponent(m_entity.m_name);
    scriptFact.deleteComponent(m_entity.m_name);
    colliderFact.deleteComponent(m_entity.m_name);
    m_entity.getComponent<ray::Mesh>("MeshFact").setActive(false);
}

void BonusBomb::takeIt(sw::Entity& entity)
{
    auto& player = entity.getComponent<Player>("ScriptFact");

    player.setMaxBomb(player.getMax() + 1);
    m_entity.getComponent<ray::Audio>("AudioFact").play("Bonus" + std::to_string((std::rand() % 3) + 1));
    destroy();
}