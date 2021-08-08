/*
** EPITECH PROJECT, 2021
** MusicFactory.cpp
** File description:
** MusicFactory.cpp
*/

#include "raylib.h"
#include "factory/MusicFact.hpp"
#include "component/Music.hpp"

void ray::MusicFact::onUpdate()
{
    for (auto& [_, name] : m_componentLayer) {
        auto& obj = *m_componentMap[name];
        UpdateMusicStream(*(*m_componentMap[name]).getMusic());
    }
}