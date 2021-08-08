/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** SdlColor.hpp
*/

#ifndef __SDL_COLOR_HPP__
#define __SDL_COLOR_HPP__

#include <unordered_map>
#include <SDL2/SDL.h>

#include "../../../inc/Color.hpp"

namespace sdl
{
    static const std::unordered_map<arc::Color, SDL_Color> sdlColorMap = {
            {arc::Color::BLACK, {0, 0, 0, 0}},
            {arc::Color::WHITE, {255, 255, 255, 0}},
            {arc::Color::RED, {255, 0, 0, 0}},
            {arc::Color::GREEN, {0, 255, 0, 0}},
            {arc::Color::BLUE, {0, 0, 255, 0}},
            {arc::Color::YELLOW, {127, 127, 0, 0}},
            {arc::Color::MAGENTA, {127, 0, 127, 0}},
            {arc::Color::CYAN, {0, 127, 127, 0}},
            {arc::Color::ORANGE, {255, 127, 0, 0}}
    };
}

#endif // __SDL_COLOR_HPP__