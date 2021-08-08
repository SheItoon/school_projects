/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ColliderFact.cpp
*/

#include "component/Collider.hpp"
#include "component/Camera.hpp"
#include "component/Movement.hpp"
#include "component/Transform.hpp"
#include "factory/ColliderFact.hpp"
#include "factory/PlayerColliderFact.hpp"
#include "Module.hpp"
#include "utils/Input.hpp"

#include <iostream>
#include <array>

void ray::PlayerColliderFact::onUpdate()
{
    if (!m_isActive)
        return;

    static bool slideMode = false;

    auto& camera = m_scene.getEntity("MainCamera").getComponent<ray::RCamera>("CameraFact");
    auto& cldFact = m_scene.getFactory<ray::ColliderFact>("ColliderFact");
    auto& module = sw::Engine::getModule<ray::Module>("RayLib");

    if (ray::Input::GetKeyPressed(ray::Keyboard::KEY_C))
        slideMode = !slideMode;

    BeginMode3D(*camera.getCamera());
    for (auto& [_, name] : m_componentLayer) {
        auto& cpt = static_cast<ray::CubeCollider&>(*m_componentMap[name]);
        auto& tfmCpt = cpt.m_entity.getComponent<ray::Transform>("TransformFact");
        auto& mvCpt = cpt.m_entity.getComponent<ray::Movement>("MovementFact");

        sw::Vector3f cpy{mvCpt.x, mvCpt.y, mvCpt.z};
        tfmCpt.move(cpy);
        auto pos = tfmCpt.getPosition();
        pos = {-pos.x, pos.y, pos.z};

        if (!cpt.isActive())
            continue;
        if (module.isDebuging())
            cpt.draw({0, 100, 255, 255});

        enum direction{UP, DOWN, LEFT, RIGHT, UPLEFT, UPRIGHT, DOWNLEFT, DOWNRIGHT, NONE};
        std::array<bool, 9> blcPos{false, false, false, false, false, false, false, false, false};


        // std::array<bool, 4> mvDir{
        //     (mvCpt.z < 0 ? true : false),
        //     (mvCpt.z > 0 ? true : false),
        //     (mvCpt.x < 0 ? true : false),
        //     (mvCpt.x > 0 ? true : false)
        // };
        // std::cout << (mvDir[UP] ? "Up\n" : "");
        // std::cout << (mvDir[DOWN] ? "Down\n" : "");
        // std::cout << (mvDir[LEFT] ? "Left\n" : "");
        // std::cout << (mvDir[RIGHT] ? "Right\n" : "");

        for (auto& [cldName, cld] : cldFact) {
            if (!(*cld).isActive())
                continue;
            if (cldName.find("Bonus") != std::string::npos) {
                if (cpt.collide(*cld))
                    (*cld).m_entity.getComponent<sw::Script>("ScriptFact").onCollision(cpt.m_entity);
                continue;
            }

            if (cpt.collide(*cld)) {
                if (slideMode) {
                    int x = std::stoi(cldName.substr(cldName.find_first_of('-') + 1));
                    int z = std::stoi(cldName.substr(cldName.find_last_of('-') + 1));

                    enum check{HORIZONTAL, VERTICAL};
                    std::array<direction, 2> checkDir{NONE, NONE};

                    std::cout << "Collide with " << cldName << std::endl;

                    if (z <= (int)pos.z) {
                        std::cout << "Up" << std::endl;
                        checkDir[HORIZONTAL] = UP;
                    }
                    if (z > (int)pos.z) {
                        std::cout << "Down" << std::endl;
                        checkDir[HORIZONTAL] = DOWN;
                    }
                    if (x < (int)pos.x) {
                        std::cout << "Left" << std::endl;
                        checkDir[VERTICAL] = LEFT;
                    }
                    if (x > (int)pos.x) {
                        std::cout << "Right" << std::endl;
                        checkDir[VERTICAL] = RIGHT;
                    }

                    if (checkDir[HORIZONTAL] == UP)
                        (checkDir[VERTICAL] == LEFT ? blcPos[UPLEFT] = true : (checkDir[VERTICAL] == RIGHT ? blcPos[UPRIGHT] = true : blcPos[UP] = true));
                    if (checkDir[HORIZONTAL] == DOWN)
                        (checkDir[VERTICAL] == LEFT ? blcPos[DOWNLEFT] = true : (checkDir[VERTICAL] == RIGHT ? blcPos[DOWNRIGHT] = true : blcPos[DOWN] = true));
                    (checkDir[VERTICAL] == LEFT ? blcPos[LEFT] = true : (checkDir[VERTICAL] == RIGHT ? blcPos[RIGHT] = true : blcPos[NONE] = true));
                }
                else {
                    if (mvCpt.z != 0)
                        mvCpt.z = 0;
                    if (mvCpt.x != 0)
                        mvCpt.x = 0;
                }
            }
        }

        if (slideMode) {
            for (auto& boolean : blcPos)
                std::cout << std::boolalpha << boolean << " / ";
            std::cout << std::endl;

            if (blcPos[UP] || blcPos[DOWN])
                mvCpt.z = 0;
            if (blcPos[LEFT] || blcPos[RIGHT])
                mvCpt.x = 0;
        }

        tfmCpt.move(-cpy);
    }
    EndMode3D();
}
