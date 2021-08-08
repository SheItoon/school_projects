/*
** EPITECH PROJECT, 2021
** mob
** File description:
** mob
*/


#include "component/components.hpp"
#include "utils/Input.hpp"
#include "Module.hpp"
#include "script/Mob.hpp"
#include <iostream>
#include <algorithm>
#include <random>
#include <future>
#include "script/GameManager.hpp"

Mob::Mob(sw::Entity &entity): Player(entity)
{
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");
    auto& ray = m_entity.createComponent<ray::RayCollider>("RayIAColliderFact");

    ray.setOrigin({0, 0.1, 0});
    ray.setDirection({0});
    ray.setActive(false);
    m_entity.createComponent<ray::Mesh>("MeshFact").setModel("Player");
    m_directions = {
        {0, 25},
        {26, 50},
        {51, 75},
        {76, 100}
    };
    m_state = WALK;
    m_life = 0;
    m_name = "";
    trans.setScale(6, 6, 6);
    m_speed = 10;
    m_distance = 0.0f;
    m_dir = NORTH;
}

Mob::Mob(sw::Entity &entity, std::string& name): Player(entity), m_name(name)
{
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");
    auto& ray = m_entity.createComponent<ray::RayCollider>("RayIAColliderFact");

    ray.setOrigin({0, 0.1, 0});
    ray.setDirection({0});
    ray.setActive(false);
    m_entity.createComponent<ray::Mesh>("MeshFact").setModel("Perso");
    m_directions = {
        {0, 25},
        {26, 50},
        {51, 75},
        {76, 100}
    };
    m_life = 0;
    m_state = WALK;
    trans.setScale(10, 10, 10);
    m_speed = 10;
    m_distance = 0.0f;
    m_dir = NORTH;
}

Mob::Mob(sw::Entity &entity, std::string &name, int life): Player(entity), m_name(name), m_life(life)
{
    auto& trans = m_entity.createComponent<ray::Transform>("TransformFact");
    auto& ray = m_entity.createComponent<ray::RayCollider>("RayIAColliderFact");

    ray.setOrigin({0, 0.1, 0});
    ray.setDirection({0});
    ray.setActive(false);
    m_directions = {
        {0, 25},
        {26, 50},
        {51, 75},
        {76, 100}
    };
    m_state = WALK;
    trans.setScale(6, 6, 6);
    m_speed = 10;
    m_distance = 0.0f;
    m_dir = NORTH;
}

void Mob::start()
{
    switch (m_player) {
        case 0:
            m_origin = {30, 60};
            break;
        case 1:
            m_origin = {1500, 60};
            break;
        case 2:
            m_origin = {30, 800};
            break;
        case 3:
            m_origin = {1500, 800};
            break;
    }
    m_entity.createComponent<ray::Mesh>("MeshFact");
    m_entity.insertComponent<ray::Collider, ray::CubeCollider>("IAColliderFact", Vector3{-0.05, -0.05, -0.05}, Vector3{0.1, 0.2, 0.1});
    m_entity.createComponent<ray::Movement>("MovementFact");
    CreateIcon();
}

void Mob::update()
{
    if (m_entity.m_scene.getEntity("GameManager").getComponent<GameManager>("ScriptFact").getGameState() != GameManager::INGAME)
        return;
    if (getLive()) {
        scout();
        (this->*this->Mob::function[this->Mob::m_state])();
    }
}

bool Mob::isBlocked(int way)
{
    if (std::find(m_blacklist.begin(), m_blacklist.end(), way) != m_blacklist.end())
        return (true);
    return (false);
}

bool Mob::in_range(int n, std::pair<int, int> range, int way)
{
    if ((n >= range.first && n <= range.second) && !isBlocked(way))
        return (m_dir = (m_card)way, true);
    return (false);
}

bool Mob::in_ranges(int path, directions dir)
{
    for (int i = 0; i < dir.size(); i++) {
        if (in_range(path, dir.at(i), i))
            return (true);
    }
    return (false);
}

void Mob::move()
{
    float time;
    auto& trans = m_entity.getComponent<ray::Transform>("TransformFact");
    auto& mov = m_entity.getComponent<ray::Movement>("MovementFact");
    auto& rayCld = m_entity.getComponent<ray::RayCollider>("RayIAColliderFact");

    m_distance = (m_distance >= 0.01f) ? m_distance : (float)(m_uniform_real_dist(m_gen));
    switch (m_dir) {
    case NORTH: time = dynamic_cast<ray::Module&>(sw::Engine::activeModule()).getDeltaTime();
        mov.setVector({0.f * m_speed * time, 0, 1.f * m_speed * time});
        trans.setRotation(0);
        rayCld.setDirection({0, 0, 1});
        break;
    case SOUTH: time = dynamic_cast<ray::Module&>(sw::Engine::activeModule()).getDeltaTime();
        mov.setVector({0.f * m_speed * time, 0, -1.f * m_speed * time});
        trans.setRotation(180);
        rayCld.setDirection({0, 0, -1});
        break;
    case EAST: time = dynamic_cast<ray::Module&>(sw::Engine::activeModule()).getDeltaTime();
        mov.setVector({1.f * m_speed * time, 0, 0.f * m_speed * time});
        trans.setRotation(90);
        rayCld.setDirection({1, 0, 0});
        break;
    case WEST: time = dynamic_cast<ray::Module&>(sw::Engine::activeModule()).getDeltaTime();
        mov.setVector({-1.f * m_speed * time, 0, 0.f * m_speed * time});
        trans.setRotation(-90);
        rayCld.setDirection({-1, 0, 0});
        break;
    default: std::cerr << "Unknown direction" << std::endl;
        break;
    }
    m_distance -= 1 * time;
}

void Mob::walking()
{
    bool found = false;

    if (ray::Input::GetKeyPressed((ray::Keyboard)KEY_SPACE)) {
        auto& trans = m_entity.getComponent<ray::Transform>("TransformFact");
        trans.setPosition(0,0,0);
    }
    if (m_distance <= 0.01f)
        for (int i = 0; !found; i++) {
            if ((found = in_ranges(m_uniform_int_dist(m_gen), m_directions)))
                move();
        } else
        move();
}

/* walking seems to do the job
void Mob::fleeing()
{

}
*/

void Mob::scout()
{
    //clear loop variable and list for next turn
    m_blacklist.clear();
    auto& ray = m_entity.getComponent<ray::RayCollider>("RayIAColliderFact");

    ray.setActive(true);
    ray.setDirection({1, 0, 0});
    auto rayTest = ray.ray().direction;
    //Ray test = rayFact.ray();
    //if (GetRayCollisionQuad(test, ))
    /* todo check walls and bomb */
    m_state = RUN;
}

void Mob::chasing()
{
    m_state = WALK;
}

void Mob::bombing()
{
    m_state = WALK;
}

/*
Mob & Mob::takeDamage()
{
    m_entity.setActive(false);
    m_entity.m_scene.getEntity("GameManager").getComponent<GameManager>("ScriptFact").playerDeath(m_entity.m_name, "Player");
    return (*this);
}*/