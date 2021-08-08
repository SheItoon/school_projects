/*
** EPITECH PROJECT, 2021
** BillBoardFact.cpp
** File description:
** BillBoardFact.cpp
*/

#include "factory/TransformFact.hpp"
#include "factory/BillBoardFact.hpp"
#include "component/BillBoard.hpp"
#include "component/Camera.hpp"
#include "component/Transform.hpp"
#include "raylib.h"

void ray::BillBoardFact::onUpdate()
{
    auto& sys = m_scene.getFactory<ray::TransformFact>("TransformFact");
    auto& camera = m_scene.getEntity("MainCamera").getComponent<ray::RCamera>("CameraFact");

    BeginMode3D(*camera.getCamera());
    for (auto& [_, entityName] : m_componentLayer) {
        auto& obj = *m_componentMap[entityName];
        if (!obj.isActive())
            continue;
        auto& trans = sys[entityName];
        DrawBillboard(*camera.getCamera(), *obj.getTexture(), {trans.getPosition().x, trans.getPosition().y, trans.getPosition().z}, 2, WHITE);
    }
    EndMode3D();
}