/*
** EPITECH PROJECT, 2021
** pacMan.cpp.c
** File description:
** pacMan.cpp.c
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include "../inc/nibbler.hpp"

__attribute__((constructor))
void nibblerConstructor()
{
    std::cout << "[Nibbler] Loading Nibbler game..." << std::endl;
}

__attribute__((destructor))
void nibblerDestructor()
{
    std::cout << "[Nibbler] Loading Nibbler stopped" << std::endl;
}

extern "C" void *entryPoint()
{
    auto *game = new Nibbler();

    std::cout << "[Nibbler] Entrypoint created." << std::endl;
    return (game);
}

Nibbler::Nibbler() : IGame()
{}

Nibbler::~Nibbler()
= default;

void Nibbler::drawing(arc::IDisplayModule *module)
{
    int spacingX = 60;
    int spacingY = 20;

    for (std::size_t line = 0; line < m_map.size(); line += 1)
        for (std::size_t col = 0; col < m_map[line].size(); col += 1)
            switch (m_map[line][col]) {
            case 'X':
                module->drawSquare(3, arc::Color::BLUE, arc::Vector<float>(col * 3 + spacingX, line * 3 + spacingY));
                break;
            case ' ':
                module->drawSquare(3, arc::Color::YELLOW, arc::Vector<float>(col * 3 + spacingX, line * 3 + spacingY));
                break;
            case 'o':
                module->drawSquare(3, arc::Color::RED, arc::Vector<float>(col * 3 + spacingX, line * 3 + spacingY));
            }
    module->drawSquare(3, arc::Color::GREEN, arc::Vector<float>(x + spacingX, y + spacingY));
    module->drawText("Score : " + std::to_string(score), 30, arc::WHITE, {20, 50});
    module->drawText("Speed : " + std::to_string(speed_mult), 30, arc::WHITE, {20, 70});
}

void Nibbler::start(arc::IDisplayModule* module)
{
    (void)module;
    std::ifstream filestream("rsc/nibblerMap.txt");

    direction = None;
    wantedDirection = None;
    x = 6;
    y = 6;
    score = 0;
    over = false;
    spawned = false;
    speed_mult = 1;
    for (int line = 0; std::getline(filestream, m_map[line]); line += 1);
}

void Nibbler::checkDirection(arc::IDisplayModule *module)
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

void Nibbler::gameOver(arc::IDisplayModule *module)
{
    if (!over)
        over = true;
    module->checkEvent();
    module->clearWindow();
    module->drawText("GAME OVER, PRESS P TO ACCESS MENU", 30, arc::WHITE, {50, 50});
    module->displayWindow();
}

int Nibbler::chooseDirection(arc::IDisplayModule *module)
{
    int posX = x / 3;
    int posY = y / 3;

    if ((direction == Up || direction == Down) && fmod(y, 3) != 0)
        return (0);
    if ((direction == Left || direction == Right) && fmod(x, 3) != 0)
        return (0);
    speed_mult *= 1 + (score / 1200);
    if (speed_mult > 3)
        speed_mult = 3;
    if (wantedDirection == Up && m_map[posY - (1)][posX] != 'X')
        return (direction = Up);
    else if (wantedDirection == Down && m_map[posY + (1)][posX] != 'X')
        return (direction = Down);
    else if (wantedDirection == Left && m_map[posY][posX - (1)] != 'X')
        return (direction = Left);
    else if (wantedDirection == Right && m_map[posY][posX + (1)] != 'X')
        return (direction = Right);
    else if (wantedDirection != None)
        gameOver(module);
    return (0);
}

void Nibbler::makeDirection()
{
    int posX = x / 3;
    int posY = y / 3;

    if (direction == Up
        && (fmod(y, 3) != 0 || m_map[posY - (1)][posX] != 'X'))
        y -= 0.5 * speed_mult;
    else if (direction == Down
             && (fmod(y, 3) != 0 || m_map[posY + (1)][posX] != 'X'))
        y += 0.5 * speed_mult;
    else if (direction == Left
             && (fmod(x, 3) != 0 || m_map[posY][posX - (1)] != 'X'))
        x -= 0.5 * speed_mult;
    else if (direction == Right
             && (fmod(x, 3) != 0 || m_map[posY][posX + (1)] != 'X'))
        x += 0.5 * speed_mult;
}

void Nibbler::checkAround()
{
    int posX = x / 3;
    int posY = y / 3;

    if (m_map[posY][posX] == 'o') {
        score += 100;
        m_map[posY][posX] = ' ';
        spawned = false;
    }
    if (posY == 10 && posX == 24)
        x = 1 * 3;
    else if (posY == 10 && posX == 0)
        x = 23 * 3;
}


void Nibbler::spawnFruit()
{
    int randX;
    int randY;
    bool find = false;

    if (!spawned) {
        while (find == false) {
            find = true;
            randX = std::rand() % m_map.size();
            randY = std::rand() % m_map.at(randX).length();
            if (m_map[randX][randY] != ' ')
                find = false;
        }
        m_map[randX][randY] = 'o';
        spawned = true;
    }
}

void Nibbler::update(arc::IDisplayModule* module)
{
    if (!over) {
        module->clearWindow();
        module->checkEvent();
        spawnFruit();
        checkDirection(module);
        chooseDirection(module);
        makeDirection();
        checkAround();
        drawing(module);
        module->displayWindow();
    } else
        gameOver(module);
}

void Nibbler::terminate(arc::IDisplayModule *)
{
    std::ifstream stream("./rsc/arcade_data.txt");
    std::vector<std::string> lineTxt;
    int index;
    std::string content;

    for (int line = 0; getline(stream, content); line += 1)
        lineTxt.push_back(content);
    std::ofstream output("./rsc/arcade_data.txt");
    for (auto & line : lineTxt) {
        index = line.find_first_of(':');
        if (line.substr(0, index) == "nibbler")
            line.replace(index + 1, line.size(), std::to_string(score));
        output << line << std::endl;
        std::cout << line << std::endl;
    }
    stream.close();
    output.close();
}