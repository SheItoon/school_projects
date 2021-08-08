/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Player.cpp
*/

#include <math.h>

#include "PacMan.hpp"

Player::Player() :
    Entity(11 * gamingScale, 15 * gamingScale),
    powerUpChrono(),
    powerUp(false),
    grailled(false),
    score(0),
    grailleCombo(0)
{}

void Player::chooseDirection(const std::array<std::string, heightMap>& map)
{
    int posX = pos.x / 3;
    int posY = pos.y / 3;

    if (((direction == Up || direction == Down) && fmod(pos.y, 3) != 0)
    || ((direction == Left || direction == Right) && fmod(pos.x, 3) != 0))
        return;
    if (wantedDirection == Up && map[posY - 1][posX] != 'X')
        direction = Up;
    else if (wantedDirection == Down && map[posY + 1][posX] != 'X')
        direction = Down;
    else if (wantedDirection == Left && map[posY][posX - 1] != 'X')
        direction = Left;
    else if (wantedDirection == Right && map[posY][posX + 1] != 'X')
        direction = Right;
}

void Player::checkDirection(arc::IDisplayModule *module)
{
    if (module->getKeyDown(arc::Keyboard::Up))
        wantedDirection = Up;
    if (module->getKeyDown(arc::Keyboard::Down))
        wantedDirection = Down;
    if (module->getKeyDown(arc::Keyboard::Left))
        wantedDirection = Left;
    if (module->getKeyDown(arc::Keyboard::Right))
        wantedDirection = Right;
}

void Player::makeDirection(const std::array<std::string, heightMap>& map)
{
    int posX = pos.x / gamingScale;
    int posY = pos.y / gamingScale;

    if (direction == Up
    && (fmod(pos.y, gamingScale) != 0 || (map[posY - 1][posX] != 'X' && map[posY - 1][posX] != '-')))
        pos.y -= 0.5;
    else if (direction == Down
    && (fmod(pos.y, gamingScale) != 0 || (map[posY + 1][posX] != 'X' && map[posY + 1][posX] != '-')))
        pos.y += 0.5;
    else if (direction == Left
    && (fmod(pos.x, gamingScale) != 0 || (map[posY][posX - 1] != 'X' && map[posY][posX - 1] != '-')))
        pos.x -= 0.5;
    else if (direction == Right
    && (fmod(pos.x, gamingScale) != 0 || (map[posY][posX + 1] != 'X' && map[posY][posX + 1] != '-')))
        pos.x += 0.5;
}

void Player::checkAround(std::array<std::string, heightMap>& map, int& pacGumNb)
{
    int posX = pos.x / gamingScale;
    int posY = pos.y / gamingScale;

    if (map[posY][posX] == 'o') {
        score += 100;
        map[posY][posX] = ' ';
        pacGumNb -= 1;
    }
    if (posY == 12 && posX == 23)
        pos.x = 0 * gamingScale;
    else if (posY == 12 && posX == -1)
        pos.x = 22 * gamingScale;
}

void Player::draw(arc::IDisplayModule *module)
{
    module->drawSquare(gamingScale, arc::Color::YELLOW, {pos.x + spacingX, pos.y + spacingY});
}