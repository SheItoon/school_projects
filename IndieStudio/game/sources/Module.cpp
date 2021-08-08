/*
** EPITECH PROJECT, 2021
** Module.cpp
** File description:
** Module.cpp
*/

#include "SW/Engine.hpp"
#include "Module.hpp"
#include "scene/Main.hpp"
#include "scene/LoadingScreen.hpp"
#include "scene/MainMenu.hpp"
#include "scene/MenuSelect.hpp"
#include "scene/EndGame.hpp"
#include "scene/Credit.hpp"

void ray::Module::onInitialize()
{
    m_debug = false;

    sw::Engine::createScene<LoadingScene>("LoadingScene");
    sw::Engine::createScene<MainMenu>("MainMenu");
    sw::Engine::createScene<CreditScene>("Credit");
    sw::Engine::createScene<EndGameScene>("EndGame");
    sw::Engine::createScene<MenuSelect>("MenuSelect");
    sw::Engine::createScene<Main>("Main");
}

void ray::Module::onUpdate()
{

}

void ray::Module::onTerminate()
{

}
