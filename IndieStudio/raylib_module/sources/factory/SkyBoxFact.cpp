/*
** EPITECH PROJECT, 2021
** SkyBoxFact.cpp
** File description:
** SkyBoxFact.cpp
*/

#include "factory/SkyBoxFact.hpp"
#include "rlgl.h"
#include "component/Skybox.hpp"
#include "component/Camera.hpp"

void ray::SkyBoxFact::onUpdate()
{
    auto& skyEntity = *m_componentMap.begin()->second;
    auto& camera = m_scene.getEntity("MainCamera").getComponent<ray::RCamera>("CameraFact");

    BeginMode3D(*camera.getCamera());
    rlDisableBackfaceCulling();
    rlDisableDepthMask();
    DrawModel(skyEntity.getModel(), {0, 0, 0}, 1.0f, WHITE);
    rlEnableBackfaceCulling();
    rlEnableDepthMask();
    EndMode3D();
}