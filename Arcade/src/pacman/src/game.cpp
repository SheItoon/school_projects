/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** game.cpp
*/

#include "PacMan.hpp"

void PacMan::drawing(arc::IDisplayModule *module)
{
    for (std::size_t line = 0; line < m_map.size(); line += 1)
        for (std::size_t col = 0; col < m_map[line].size(); col += 1)
            switch (m_map[line][col]) {
                case 'X':
                    module->drawSquare(3, arc::Color::BLUE, arc::Vector<float>(col * 3 + spacingX, line * 3 + spacingY));
                    break;
                case 'P':
                    module->drawSquare(2, arc::Color::YELLOW, arc::Vector<float>(col * 3 + 0.5 + spacingX, line * 3 + 0.5 + spacingY));
                    break;
                case 'o':
                    module->drawSquare(1, arc::Color::YELLOW, arc::Vector<float>(col * 3 + 1 + spacingX, line * 3 + 1 + spacingY));
                    break;
                case '-':
                    module->drawSquare(1, arc::Color::WHITE, arc::Vector<float>(col * 3 + spacingX    , line * 3 + 1 + spacingY));
                    module->drawSquare(1, arc::Color::WHITE, arc::Vector<float>(col * 3 + 1 + spacingX, line * 3 + 1 + spacingY));
                    module->drawSquare(1, arc::Color::WHITE, arc::Vector<float>(col * 3 + 2 + spacingX, line * 3 + 1 + spacingY));
                    break;
            }
    player.draw(module);
    for (auto& ghost : ghosts)
        ghost.draw(module);
    module->drawText("PACMAN", 100, arc::YELLOW, arc::Vector<float>(10, 30));
    module->drawText("Score : " + std::to_string(player.score), 40, arc::WHITE, arc::Vector<float>(20, 50));
}