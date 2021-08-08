/*
** EPITECH PROJECT, 2021
** Movement.cpp
** File description:
** Movement.cpp
*/

#include "component/Movement.hpp"

ray::Movement::Movement(sw::Entity &entity) :
sw::Component(entity),
x(0),
y(0),
z(0)
{}

ray::Movement::Movement(sw::Entity &entity, float xVal, float yVal, float zVal):
sw::Component(entity),
x(xVal),
y(yVal),
z(zVal)
{}

ray::Movement & ray::Movement::setVector(sw::Vector3f vector)
{
    x = vector.x;
    y = vector.y;
    z = vector.z;
    return (*this);
}