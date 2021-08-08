/*
** EPITECH PROJECT, 2021
** Camera.cpp
** File description:
** Camera.cpp
*/

#include "component/components.hpp"
#include "script/MyCamera.hpp"

void MyCamera::start()
{
    m_entity.createComponent<ray::RCamera>("CameraFact").setPosition(-8, 25, 18).setTarget(-8, 0, 7);
}