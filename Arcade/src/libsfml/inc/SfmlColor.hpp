/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SfmlColor.hpp
*/

#ifndef __SFML_COLOR_HPP__
#define __SFML_COLOR_HPP__

#include <unordered_map>
#include <SFML/Graphics.hpp>

#include "../../../inc/Color.hpp"

namespace sfml
{
    static const std::unordered_map<arc::Color, sf::Color> sfmlColorMap = {
            {arc::Color::BLACK, sf::Color::Black},
            {arc::Color::WHITE, sf::Color::White},
            {arc::Color::RED, sf::Color(255, 0, 0)},
            {arc::Color::GREEN, sf::Color(0, 255, 0)},
            {arc::Color::BLUE, sf::Color(0, 0, 255)},
            {arc::Color::YELLOW, sf::Color(127, 127, 0)},
            {arc::Color::MAGENTA, sf::Color(127, 0, 127)},
            {arc::Color::CYAN, sf::Color(0, 127, 127)},
            {arc::Color::ORANGE, sf::Color(255, 127, 0)}
    };
}


#endif // __SFML_COLOR_HPP__