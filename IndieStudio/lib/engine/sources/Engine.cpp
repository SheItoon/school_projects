/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Engine.cpp
*/

#include "engine/Engine.hpp"

#include <optional>

std::unordered_map<std::string, std::unique_ptr<sw::AScene>> sw::Engine::m_sceneMap;
std::unordered_map<std::string, std::unique_ptr<sw::IModule>> sw::Engine::m_moduleMap;
std::string sw::Engine::m_activeScene;
std::string sw::Engine::m_activeModule;
std::vector<std::string> sw::Engine::m_deleteScene;

void sw::Engine::initialize()
{
    sw::Engine::onInitialize();
    sw::Engine::activeModule().initialize();
}

void sw::Engine::update()
{
    while (sw::Engine::activeModule().isOk()) {
        sw::Engine::onUpdate();
        sw::Engine::activeModule().update();
        sw::Engine::deleteRequestedScene();
    }
}

void sw::Engine::terminate()
{
    sw::Engine::onTerminate();
    sw::Engine::activeModule().terminate();

    auto sceneIt = m_sceneMap.begin();
    auto sceneNext = m_sceneMap.begin();
    auto moduleIt = m_sceneMap.begin();
    auto moduleNext = m_sceneMap.begin();

    for (; sceneIt != m_sceneMap.end(); sceneIt = sceneNext) {
        sceneNext = std::next(sceneIt, 1);
        deleteScene(sceneIt->first);
    }
    for (; moduleIt != m_sceneMap.end(); moduleIt = moduleNext) {
        moduleNext = std::next(moduleIt, 1);
        deleteModule(moduleIt->first);
    }
}