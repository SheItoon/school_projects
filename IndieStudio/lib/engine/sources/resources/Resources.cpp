/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Resources.cpp
*/

#include <iostream>
#include <fstream>

#include "resources/Resources.hpp"
#include "jsnp.hpp"
#include "scene/AScene.hpp"
#include "engine/Engine.hpp"

sw::Resources::~Resources() noexcept
{
    models.clear();
    fonts.clear();
    music.clear();
    sounds.clear();
    textures.clear();
}

void sw::Resources::loadResources()
{
    loadTextures();
    loadFonts();
    loadSounds();
    loadModel();
    loadMusic();
}

void sw::Resources::unloadResources()
{
    models.clear();
    textures.clear();
    sounds.clear();
    fonts.clear();
}

static void checkDuplicate(std::unordered_map<std::string, std::string>& list, std::string& name, std::string& path)
{
    if (list.find(name) == list.end())
        list.emplace(name, path);
}

void sw::AddResourcesOnScene(jsnp::Token& token)
{
    auto& key = token.first;
    auto& obj = token.second.value<jsnp::Object>();
    auto& path = obj["Path"].second.value<std::string>();
    auto& type = obj["Type"].second.value<std::string>();

    if (!std::ifstream(path))
        std::cout << "Warning tag Path is incorrect! (" << path << ")" << std::endl;

    for (auto& value : obj["Scene"].second.value<jsnp::Array>()) {
        auto& sceneName = value.value<std::string>();
        sw::AScene& currentScene = sw::Engine::getScene(sceneName);

        if (type == std::string("Texture"))
            checkDuplicate(currentScene.m_resources.m_neededTextures, key, path);
        else if (type == std::string("Font"))
            checkDuplicate(currentScene.m_resources.m_neededFonts, key, path);
        else if (type == std::string("Sound"))
            checkDuplicate(currentScene.m_resources.m_neededSounds, key, path);
        else if (type == std::string("Model"))
            checkDuplicate(currentScene.m_resources.m_neededModels, key, path);
        else if (type == std::string("Music"))
            checkDuplicate(currentScene.m_resources.m_neededMusic, key, path);
        else
            std::cout << "Warning tag Type incorrect!" << std::endl;
    }
}

void sw::LoadResourcesFile(const std::string &path)
{
    std::ifstream in(path);
    jsnp::Data data(path);

    if (!in) {
        std::cout << "Unable to open file " << path << std::endl;
        throw std::exception(); // TODO
    }
    for (auto& token : data()) {
        auto& obj = token.second.value<jsnp::Object>();
        if (obj["Scene"].second.value<jsnp::Array>().size() == 0) {
            std::cout << "Warning tag Scene not found!" << std::endl;
            continue;
        }
        sw::AddResourcesOnScene(token);
    }
}