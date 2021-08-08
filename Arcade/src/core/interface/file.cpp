/*
** EPITECH PROJECT, 2021
** file.cpp.c
** File description:
** file.cpp.c
*/

#include <iostream>
#include <filesystem>
#include <fstream>
#include "../../../inc/Interface.hpp"

static bool IsLibValid(const std::string &name)
{
    std::array<std::string, 13> libList = {"sfml", "sdl2", "ncurses", "ndk++", "aalib", "libcaca", "allegro5", "xlib", "gtk+", "irrlicht", "opengl", "vulkan", "qt5"};

    for (auto & it : libList)
        if (name.find("arcade_" + it + ".so") != std::string::npos)
            return (true);
    return (false);
}

static bool IsGameValid(const std::string &name)
{
    std::array<std::string, 5> gameList = {"pacman", "nibbler", "qix", "centipede", "solarfox"};

    for (auto& it : gameList)
        if (name.find("arcade_" + it + ".so") != std::string::npos)
            return (true);
    return (false);
}

void arc::Interface::getData()
{
    std::ifstream stream("./rsc/arcade_data.txt");
    std::vector<std::string> lineTxt;
    int index;
    std::string content;

    for (int line = 0; getline(stream, content); line += 1) {
        lineTxt.push_back(content);
        content.clear();
    }
    for (auto & line : lineTxt) {
        index = line.find_first_of(':');
        m_score.emplace(line.substr(0, index), line.substr(index + 1).c_str());
    }
}

void arc::Interface::getList()
{
    std::string path = "./lib";

    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (IsLibValid(entry.path()))
            m_lib.push_back(entry.path());
        if (IsGameValid(entry.path()))
            m_game.push_back(entry.path());
    }
    getData();
}