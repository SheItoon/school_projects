/*
** EPITECH PROJECT, 2021
** CameraFact.cpp
** File description:
** CameraFact.cpp
*/

#include "raylib.h"
#include "component/Camera.hpp"
#include "factory/CameraFact.hpp"

void ray::CameraFact::onUpdate()
{
    auto& cameraEntity = *m_componentMap.begin()->second;

    UpdateCamera(cameraEntity.getCamera());
}