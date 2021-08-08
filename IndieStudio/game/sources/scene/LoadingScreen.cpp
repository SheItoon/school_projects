/*
** EPITECH PROJECT, 2021
** Main.cpp
** File description:
** Main.cpp
*/

#include "scene/LoadingScreen.hpp"
#include "component/components.hpp"
#include "factory/factories.hpp"
#include "script/Logo.hpp"

void LoadingScene::onLoad()
{
    createFactory<ray::TransformFact>("TransformFact");
    createFactory<ray::SpriteFact>("SpriteFact");
    auto& scriptFact = createFactory<sw::ScriptFact>("ScriptFact");
    createFactory<ray::AudioFact>("AudioFact");

    createEntity("Logo");

    scriptFact.addScript<Logo>("Logo");
}

void LoadingScene::onUpdate()
{
    for (auto& [_, factoryName] : m_factoryLayer) {
        auto& sys = m_factoryMap[factoryName];
        //if (!sys->isActive())
        //    continue;
        //sys->neededAction();
        sys->update();
    }
}

void LoadingScene::onUnload()
{

}