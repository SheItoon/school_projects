/*
** EPITECH PROJECT, 2021
** MainMenu.cpp
** File description:
** MainMenu.cpp
*/

#include "scene/MainMenu.hpp"
#include "factory/factories.hpp"
#include "component/components.hpp"

#include "script/MenuManager.hpp"

void MainMenu::onLoad()
{
    auto& spriteFact = createFactory<ray::SpriteFact>("SpriteFact");
    auto& scriptFact = createFactory<sw::ScriptFact>("ScriptFact");
    auto& transFact = createFactory<ray::TransformFact>("TransformFact");
    auto& textFact = createFactory<ray::TextFact>("TextFact");
    createFactory<ray::MusicFact>("MusicFact");
    createFactory<ray::AudioFact>("AudioFact");
    createEntity("MenuManager");
    scriptFact.addScript<MenuManager>("MenuManager");
}

void MainMenu::onUpdate()
{}

void MainMenu::onUnload()
{}
