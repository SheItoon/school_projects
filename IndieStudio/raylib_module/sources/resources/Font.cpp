/*
** EPITECH PROJECT, 2021
** Font.cpp
** File description:
** Font.cpp
*/

#include <iostream>

#include "resources/Font.hpp"
#include "resources/Resources.hpp"

ray::RFont::RFont(Font font) : m_font(font)
{}

ray::RFont::~RFont() noexcept
{
    UnloadFont(m_font);
}

Font ray::RFont::operator*() const
{
    return (m_font);
}

void sw::Resources::loadFonts()
{
    Font new_font;

    for (auto &[name, path] : m_neededFonts) {
        new_font = LoadFont(path.c_str());
        fonts.emplace(name, std::make_shared<ray::RFont>(new_font));
    }
    if (fonts.empty())
        std::cout << "Warning no font can be loaded!" << std::endl;
}