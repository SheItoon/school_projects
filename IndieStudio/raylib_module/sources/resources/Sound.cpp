/*
** EPITECH PROJECT, 2021
** Sound.cpp
** File description:
** Sound.cpp
*/

#include <iostream>

#include "resources/Sound.hpp"
#include "resources/Resources.hpp"

ray::RSound::RSound(Sound sound) : m_sound(sound)
{}

ray::RSound::~RSound() noexcept
{
    StopSoundMulti();
    UnloadSound(m_sound);
}

Sound ray::RSound::operator*()
{
    return (m_sound);
}

void sw::Resources::loadSounds()
{
    Sound new_sound;

    for (auto &[name, path] : m_neededSounds) {
        new_sound = LoadSound(path.c_str());
        sounds.emplace(name, std::make_shared<ray::RSound>(new_sound));
    }
    if (sounds.empty())
        std::cout << "Warning no sound can be loaded!" << std::endl;
}