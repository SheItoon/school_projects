/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-guillaume.soisson
** File description:
** LoadManager
*/

#pragma once

#include <vector>
#include <map>
#include <string>

#include "SW/Scene.hpp"


class LoadManager {
    public:
        LoadManager() = default;
        ~LoadManager() = default;
        void loadGame(std::string const& savePath, sw::AScene& scene);
    protected:
    private:
        void loadCharacters();
};
