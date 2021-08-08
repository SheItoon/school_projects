/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Entity.cpp
*/

#include <math.h>

#include "PacMan.hpp"

Entity::Entity(float xVal, float yVal) :
    direction(None),
    wantedDirection(None),
    pos(xVal, yVal)
{}