/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ColliderFact.cpp
*/

#include "component/Collider.hpp"
#include "component/Camera.hpp"
#include "component/Movement.hpp"
#include "script/Mob.hpp"
#include "script/Cube.hpp"
#include "factory/ColliderFact.hpp"
#include "component/Transform.hpp"
#include "factory/PlayerColliderFact.hpp"
#include "factory/RayIAColliderFact.hpp"
#include "Module.hpp"

#include <iostream>

void ray::RayIAColliderFact::onUpdate()
{
    if (!m_isActive)
        return;

    auto& camera = m_scene.getEntity("MainCamera").getComponent<ray::RCamera>("CameraFact");
    auto& cldFact = m_scene.getFactory<ray::ColliderFact>("ColliderFact");
    auto& plyCldFact = m_scene.getFactory<ray::PlayerColliderFact>("PlayerColliderFact");
    auto& module = sw::Engine::getModule<ray::Module>("RayLib");

    BeginMode3D(*camera.getCamera());
    for (auto& [_, name] : m_componentLayer) {
        std::cout << name << std::endl;
        auto& cpt = *m_componentMap[name];
        auto& mobScript = cpt.m_entity.getComponent<Mob>("ScriptFact");

        if (!cpt.isActive())
            continue;
        if (module.isDebuging())
            cpt.draw({100, 0, 255, 255});

        auto& mvCpt = cpt.m_entity.getComponent<ray::Movement>("MovementFact");
        auto& tfmCpt = cpt.m_entity.getComponent<ray::Transform>("TransformFact");

        if (cpt.type() == ray::Collider::RAY) {
            auto& ray = static_cast<ray::RayCollider&>(cpt);

            // Player
            for (auto& [cldName, plyCld] : plyCldFact) {
                if (!(*plyCld).isActive())
                    continue;
                if (ray.collide(*plyCld))
                    mobScript.m_state = Mob::CHASE;
            }

            // Other
            for (auto& [cldName, cld] : cldFact) {
                if (!(*cld).isActive()
                || cldName.find("Bonus") != std::string::npos)
                    continue;

                auto info = ray.collideWInfo(*cld);

                if (cldName.find("Bomb") != std::string::npos) {
                    if (ray.ray().direction.x == -1)
                        mobScript.m_blacklist.push_back(Mob::EAST);
                    else if (ray.ray().direction.x == 1)
                        mobScript.m_blacklist.push_back(Mob::WEST);
                    else if (ray.ray().direction.z == -1)
                        mobScript.m_blacklist.push_back(Mob::NORTH);
                    else if (ray.ray().direction.z == 1)
                        mobScript.m_blacklist.push_back(Mob::SOUTH);
                } else if (info.hit) {
                    auto type = cld->m_entity.getComponent<Cube>("ScriptFact").getType();
                    if (info.distance < 1) {
                        if (type == Cube::BREAKABLE)
                            mobScript.SpawnBomb();
                        else if (type == Cube::UNBREAKABLE) {
                            if (ray.ray().direction.x == -1)
                                mobScript.m_blacklist.push_back(Mob::EAST);
                            else if (ray.ray().direction.x == 1)
                                mobScript.m_blacklist.push_back(Mob::WEST);
                            else if (ray.ray().direction.z == -1)
                                mobScript.m_blacklist.push_back(Mob::NORTH);
                            else if (ray.ray().direction.z == 1)
                                mobScript.m_blacklist.push_back(Mob::SOUTH);
                        }
                    }
                }
            }
        }
    }
    EndMode3D();
}
