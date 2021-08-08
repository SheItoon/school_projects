/*
** EPITECH PROJECT, 2021
** MenuSelect.cpp
** File description:
** MenuSelect.cpp
*/

#include "scene/MenuSelect.hpp"
#include "factory/factories.hpp"
#include "component/components.hpp"
#include "utils/Input.hpp"
#include "save_load/SaveManager.hpp"
#include "Module.hpp"

#include "script/SelectionManager.hpp"
#include "script/MyCamera.hpp"

void MenuSelect::onLoad()
{
    auto& cameraFact = createFactory<ray::CameraFact>("CameraFact");
    auto& spriteFact = createFactory<ray::SpriteFact>("SpriteFact");
    auto& scriptFact = createFactory<sw::ScriptFact>("ScriptFact");
    createFactory<ray::SpriteFact>("BackGroundFact");
    auto& textFact = createFactory<ray::TextFact>("TextFact");
    auto& transFact = createFactory<ray::TransformFact>("TransformFact");
    auto& musicFact = createFactory<ray::MusicFact>("MusicFact");
    auto& meshFact = createFactory<ray::MeshFact>("MeshFact");
    auto& audioFact = createFactory<ray::AudioFact>("AudioFact");

    setLayer("BackGroundFact", -1);
    setLayer("CameraFact", 0);
    setLayer("MeshFact", 1);
    setLayer("TransformFact", 2);
    setLayer("ScriptFact", 3);
    setLayer("SpriteFact", 4);
    setLayer("TextFact", 5);

    createEntity("Music").createComponent<ray::MusicStream>("MusicFact").addSound("MenuSelect", "Music").play("Music");
    createEntity("MainCamera").createComponent<ray::RCamera>("CameraFact").setPosition(-8, 0, 10).setProjection(CAMERA_ORTHOGRAPHIC);

    createEntity("SelectionManager");
    dynamic_cast<SelectionManager&>(scriptFact.addScript<SelectionManager>("SelectionManager")).resetSelection();
    sw::Engine::activeModule<ray::Module>().SetBackGroundColor(BLUE);
}

void MenuSelect::onUpdate()
{}

void MenuSelect::onUnload() {}