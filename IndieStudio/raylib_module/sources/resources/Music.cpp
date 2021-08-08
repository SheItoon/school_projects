/*
** EPITECH PROJECT, 2021
** Music.cpp
** File description:
** Music.cpp
*/

#include <iostream>

#include "resources/Music.hpp"
#include "resources/Resources.hpp"

ray::RMusic::RMusic(Music music) : m_music(music)
{}

ray::RMusic::~RMusic() noexcept
{
    UnloadMusicStream(m_music);
}

Music ray::RMusic::operator*()
{
    return (m_music);
}

void sw::Resources::loadMusic()
{
    Music new_sound;

    for (auto &[name, path] : m_neededMusic) {
        new_sound = LoadMusicStream(path.c_str());
        music.emplace(name, std::make_shared<ray::RMusic>(new_sound));
    }
    if (music.empty())
        std::cout << "Warning no music can be loaded!" << std::endl;
}