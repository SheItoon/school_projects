/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Ghost.cpp
*/

#include <math.h>
#include <iostream>

#include "PacMan.hpp"

Ghost::Ghost(arc::Vector<float> pos, arc::Color colorVal) :
    Entity(pos.x * gamingScale, pos.y * gamingScale),
    dirChoiceChrono(arc::Chrono::Lauch),
    color(colorVal),
    mode(Hunting),
    needMoveChoice(false),
    houseKeeping(true)
{}

std::array<bool, 4> Ghost::checkPossibleDirection(const std::array<std::string, heightMap>& map)
{
    std::array<bool, 4> possibleDirection = {true, true, true, true};
    int posX = pos.x / gamingScale;
    int posY = pos.y / gamingScale;

    if (direction == Down || map[posY - 1][posX] == 'X' || map[posY - 1][posX] == 'x')
        possibleDirection[Up] = false;
    if (direction == Up || map[posY + 1][posX] == 'X' || map[posY + 1][posX] == 'x')
        possibleDirection[Down] = false;
    if (direction == Right || map[posY][posX - 1] == 'X' || map[posY][posX - 1] == 'x')
        possibleDirection[Left] = false;
    if (direction == Left || map[posY][posX + 1] == 'X' || map[posY][posX + 1] == 'x')
        possibleDirection[Right] = false;
    return (possibleDirection);
}

arc::Vector<float> Ghost::determineTarget(bool houseKeeping, Ghost::mode_e mode, const arc::Vector<float> playerPos)
{
    switch (mode) {
        case Grailled:
            return (arc::Vector<float>(11, 12));
        case Hunting:
            if (houseKeeping)
                return (arc::Vector<float>(11, 9));
            return (arc::Vector<float>(playerPos.x / gamingScale, playerPos.y / gamingScale));
        default:
            return (arc::Vector<float>(100, 100));
    }
}

void Ghost::settleDirection(std::array<bool, 4> possibleDirection, const arc::Vector<float> target)
{
    arc::Vector<float> distanceToTarget = {100, 100};
    int posX = pos.x / gamingScale;
    int posY = pos.y / gamingScale;

    if (possibleDirection[Up] && distanceToTarget > arc::Vector<float>(target.x - posX, target.y - (posY - 1))) {
        distanceToTarget = {target.x - posX, target.y - (posY - 1)};
        direction = Up;
    }
    if (possibleDirection[Down] && distanceToTarget > arc::Vector<float>(target.x - posX, target.y - (posY + 1))) {
        distanceToTarget = {target.x - posX, target.y - (posY + 1)};
        direction = Down;
    }
    if (possibleDirection[Left] && distanceToTarget > arc::Vector<float>(target.x - (posX - 1), target.y - posY)) {
        distanceToTarget = {target.x - (posX - 1), target.y - posY};
        direction = Left;
    }
    if (possibleDirection[Right] && distanceToTarget > arc::Vector<float>(target.x - (posX + 1), target.y - posY)) {
        distanceToTarget = {target.x - (posX + 1), target.y - posY};
        direction = Right;
    }
}

void Ghost::settleRandomDirection(std::array<bool, 4> possibleDirection)
{
    int random = std::rand() % 4;

    while (!possibleDirection[random])
        random = std::rand() % 4;
    direction = (direction_e)random;
}

void Ghost::chooseDirection(const std::array<std::string, heightMap>& map, const arc::Vector<float> playerPos)
{
    if (fmod(pos.y, gamingScale) != 0 || fmod(pos.x, gamingScale) != 0)
        return;

    if (dirChoiceChrono.getElapsedTime() > 3) {
        if (mode == Hunting)
            mode = Random;
        else if (mode == Random)
            mode = Hunting;
        dirChoiceChrono.tour();
    }

    std::array<bool, 4> possibleDirection = checkPossibleDirection(map);
    arc::Vector<float> target = determineTarget(houseKeeping, mode, playerPos);

    if (target.x == 100)
        settleRandomDirection(possibleDirection);
    else
        settleDirection(possibleDirection, target);
}

void Ghost::makeDirection(const std::array<std::string, heightMap>& map)
{
    (void)map;

    if (direction == Up)
        pos.y -= (mode == PowerLess ? 0.25 : 0.5);
    else if (direction == Down)
        pos.y += (mode == PowerLess ? 0.25 : 0.5);
    else if (direction == Left)
        pos.x -= (mode == PowerLess ? 0.25 : 0.5);
    else if (direction == Right)
        pos.x += (mode == PowerLess ? 0.25 : 0.5);
}

void Ghost::checkAround()
{
    int posX = pos.x / gamingScale;
    int posY = pos.y / gamingScale;

    if (10 <= posY && posY < 15 && 8 < posX && posX < 14)
        houseKeeping = true;
    else
        houseKeeping = false;
    if (houseKeeping && mode == Grailled)
        mode = Hunting;
}

void Ghost::draw(arc::IDisplayModule *module)
{
    if (mode != Grailled)
        module->drawSquare(gamingScale, (mode == PowerLess ? arc::Color::CYAN : color), {pos.x + spacingX, pos.y + spacingY});
    module->drawSquare(1, arc::Color::WHITE, {pos.x + spacingX, pos.y + spacingY + 1});
    module->drawSquare(1, arc::Color::WHITE, {pos.x + spacingX + 2, pos.y + spacingY + 1});
}