/*
** EPITECH PROJECT, 2021
** DLManager.cpp.cc
** File description:
** DLManager.cpp.cc
*/

#include "../../inc/DLManager.hpp"

arc::DLManager::DLManager(const std::string& path) :
m_module(std::make_unique<DLLoader>(path)),
m_game(nullptr),
m_moduleFunc(nullptr),
m_gameFunc(nullptr),
m_needGraphUpdate(false),
m_needGameUpdate(false),
m_newGraph(),
m_newGame(),
state(MENU)
{
    m_moduleFunc = m_module->getInstance<arc::IDisplayModule>();
}

arc::DLManager::~DLManager()
{
    delete (m_moduleFunc);
    delete (m_gameFunc);
}

void arc::DLManager::ChangeGraphicModule(const std::string module)
{
    m_newGraph = module;
    m_needGraphUpdate = true;
}

void arc::DLManager::ChangeGameModule(const std::string module)
{
    m_newGame = module;
    m_needGameUpdate = true;
}

arc::DLLoader& arc::DLManager::getGraphicsModule()
{
    return (*m_module);
}

arc::DLLoader& arc::DLManager::getGameModule()
{
    return (*m_game);
}

arc::IDisplayModule* arc::DLManager::getGraphicsInstance()
{
    return (m_moduleFunc);
}

arc::IGame* arc::DLManager::getGameInstance()
{
    return (m_gameFunc);
}

void arc::DLManager::updateGraphics()
{
    if (!m_needGraphUpdate)
        return;
    delete (m_moduleFunc);
    m_module = std::make_unique<DLLoader>(m_newGraph);
    m_moduleFunc = m_module->getInstance<IDisplayModule>();
    m_needGraphUpdate = false;
}

void arc::DLManager::updateGame()
{
    if (!m_needGameUpdate)
        return;
    if (m_gameFunc)
        m_gameFunc->terminate(m_moduleFunc);
    delete (m_gameFunc);
    m_game = std::make_unique<DLLoader>(m_newGame);
    m_gameFunc = m_game->getInstance<arc::IGame>();
    m_needGameUpdate = false;
    m_gameFunc->start(m_moduleFunc);
}