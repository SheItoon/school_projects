/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** pacMan.cpp
*/

#include <iostream>
#include <fstream>

#include "PacMan.hpp"

__attribute__((constructor))
void pacManConstructor()
{
    std::cout << "[PacMan] Loading PacMan game..." << std::endl;
}

__attribute__((destructor))
void pacManDestructor()
{
    std::cout << "[PacMan] PacMan game stopped." << std::endl;
}

extern "C" void *entryPoint()
{
    auto *game = new PacMan();

    std::cout << "[PacMan] Entrypoint created." << std::endl;
    return (game);
}

PacMan::PacMan() :
    player(),
    ghosts({Ghost({9, 12}, arc::Color::GREEN),
            Ghost({9, 13}, arc::Color::MAGENTA),
            Ghost({13, 12}, arc::Color::RED),
            Ghost({13, 13}, arc::Color::ORANGE)}),
    m_map(),
    pacGumNb(191)
{}

void PacMan::start(arc::IDisplayModule* module)
{
    (void)module;
    std::ifstream filestream("rsc/pacmanMap.txt");

    std::srand(std::time(NULL));
    for (int line = 0; std::getline(filestream, m_map[line]); line += 1);
    filestream.close();
}

void PacMan::terminate(arc::IDisplayModule* module)
{
    (void)module;
}

void PacMan::playerTurn(arc::IDisplayModule *module)
{
    player.checkDirection(module);
    player.chooseDirection(m_map);
    player.makeDirection(m_map);
    player.checkAround(m_map, pacGumNb);
}

void PacMan::ghostTurn()
{
    static arc::Chrono startingChrono(arc::Chrono::Lauch);

    if (startingChrono.getElapsedTime() < waitGhostStart)
        return;
    startingChrono.stop();
    for (auto& ghost : ghosts) {
        ghost.chooseDirection(m_map, {player.pos.x, player.pos.y});
        ghost.makeDirection(m_map);
        ghost.checkAround();
    }
}

void PacMan::checkBoth()
{
    int pPosX = player.pos.x / gamingScale;
    int pPosY = player.pos.y / gamingScale;

    if (m_map[pPosY][pPosX] == 'P') {
        player.powerUp = true;
        player.powerUpChrono.start();
        for (auto& ghost : ghosts) {
            if (ghost.mode != Ghost::mode_e::Grailled)
                ghost.mode = Ghost::mode_e::PowerLess;
            if (ghost.direction == Entity::direction_e::Up)
                ghost.direction = Entity::direction_e::Down;
            else if (ghost.direction == Entity::direction_e::Down)
                ghost.direction = Entity::direction_e::Up;
            else if (ghost.direction == Entity::direction_e::Left)
                ghost.direction = Entity::direction_e::Right;
            else if (ghost.direction == Entity::direction_e::Right)
                ghost.direction = Entity::direction_e::Left;
        }
        player.score += 100;
        m_map[pPosY][pPosX] = ' ';
        pacGumNb -= 1;
    }
    else if (player.powerUp && player.powerUpChrono.getElapsedTime() > powerUpTime) {
        player.powerUp = false;
        for (auto& ghost : ghosts)
            if (ghost.mode == Ghost::mode_e::PowerLess)
                ghost.mode = Ghost::mode_e::Hunting;
        player.powerUpChrono.stop();
        player.grailleCombo = 0;
    }
    for (auto& ghost : ghosts)
        if (abs(player.pos.x - ghost.pos.x) < 3 && abs(player.pos.y - ghost.pos.y) < 3) {
            if (player.powerUp) {
                if (ghost.mode != Ghost::mode_e::Grailled) {
                    ghost.mode = Ghost::mode_e::Grailled;
                    ghost.pos.x = (fmod(ghost.pos.x, 1) == 0.75 || fmod(ghost.pos.x, 1) == 0.25 ? ghost.pos.x + 0.25 : ghost.pos.x);
                    ghost.pos.y = (fmod(ghost.pos.y, 1) == 0.75 || fmod(ghost.pos.y, 1) == 0.25 ? ghost.pos.y + 0.25 : ghost.pos.y);
                    player.grailleCombo += 1;
                    player.score += 200 * pow(2, player.grailleCombo);
                }
            } else
                player.grailled = true;
        }
}

static void lose(arc::IDisplayModule *module)
{
    module->drawText("You Lose !", 50, arc::WHITE, {20, 60});
    module->drawText("Press P to access menu", 30, arc::WHITE, {21, 65});
    module->drawText("or press r to reload", 30, arc::WHITE, {21, 68});
}

static void win(arc::IDisplayModule *module)
{
    module->drawText("You Win !", 50, arc::WHITE, {20, 60});
    module->drawText("Press P to access menu", 30, arc::WHITE, {21, 65});
    module->drawText("or press r to reload", 30, arc::WHITE, {21, 68});
}

void PacMan::update(arc::IDisplayModule *module)
{
    module->clearWindow();
    module->checkEvent();
    if (player.grailled)
        lose(module);
    else if (pacGumNb) {
        playerTurn(module);
        ghostTurn();
        checkBoth();
    } else
        win(module);
    drawing(module);
    module->displayWindow();
}