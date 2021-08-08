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
#include "factory/IAColliderFact.hpp"
#include "Module.hpp"

#include <iostream>

void ray::IAColliderFact::onUpdate()
{
    if (!m_isActive)
        return;

    auto& camera = m_scene.getEntity("MainCamera").getComponent<ray::RCamera>("CameraFact");
    auto& cldFact = m_scene.getFactory<ray::ColliderFact>("ColliderFact");
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

        if (cpt.type() == ray::Collider::CUBE) {
            auto& cube = static_cast<ray::CubeCollider&>(cpt);

            for (auto& [cldName, cld] : cldFact) {
                if (!(*cld).isActive()
                || cldName.find("Bomb") != std::string::npos)
                    continue;
                if (cldName.find("Bonus") != std::string::npos) {
                    if (cpt.collide(*cld))
                        (*cld).m_entity.getComponent<sw::Script>("ScriptFact").onCollision(cpt.m_entity);
                    continue;
                }

                sw::Vector3f cpy{mvCpt.x, mvCpt.y, mvCpt.z};
                tfmCpt.move(cpy);
                if (cube.collide(*cld)) {
                    if (mvCpt.z != 0)
                        mvCpt.z = 0;
                    if (mvCpt.x != 0)
                        mvCpt.x = 0;
                }
                tfmCpt.move(-cpy);
            }
        }
    }
    EndMode3D();
}
