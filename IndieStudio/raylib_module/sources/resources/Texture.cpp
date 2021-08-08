/*
** EPITECH PROJECT, 2021
** Texture.cpp
** File description:
** Texture.cpp
*/

#include <iostream>

#include "resources/Texture.hpp"
#include "resources/Resources.hpp"

ray::RTexture::RTexture(Texture2D texture) : m_texture(texture)
{}

ray::RTexture::~RTexture() noexcept
{
    UnloadTexture(m_texture);
}

Texture2D ray::RTexture::operator*() const
{
    return (m_texture);
}

void sw::Resources::loadTextures()
{
    Texture2D new_texture;

    for (auto &[name, path] : m_neededTextures) {
        new_texture = LoadTexture(path.c_str());
        textures.emplace(name, std::make_shared<ray::RTexture>(new_texture));
    }
    if (textures.empty())
        std::cout << "Warning no texture can be loaded" << std::endl;
}