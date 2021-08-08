/*
** EPITECH PROJECT, 2021
** Main.cpp
** File description:
** Main.cpp
*/

#include "scene/Main.hpp"
#include "component/components.hpp"
#include "factory/factories.hpp"
#include "save_load/SaveManager.hpp"
#include "save_load/LoadManager.hpp"

#include "script/MyCamera.hpp"
#include "script/MapGenerator.hpp"
#include "script/Mob.hpp"
#include "script/GameManager.hpp"
#include "script/PauseManager.hpp"

#include "map/Map.hpp"
#include "indie.hpp"
#include "jsnp.hpp"

Main::loadMode_e Main::loadMode = Main::NEW_GAME;

void Main::onLoad()
{

    auto& scriptFact = createFactory<sw::ScriptFact>("ScriptFact");
    createFactory<ray::CameraFact>("CameraFact");
    createFactory<ray::SpriteFact>("SpriteFact");
    createFactory<ray::TextFact>("TextFact");
    createFactory<ray::MeshFact>("MeshFact");
    createFactory<ray::TransformFact>("TransformFact");
    createFactory<ray::SkyBoxFact>("SkyboxFact");
    createFactory<ray::ColliderFact>("ColliderFact");
    createFactory<ray::PlayerColliderFact>("PlayerColliderFact");
    createFactory<ray::IAColliderFact>("IAColliderFact");
    createFactory<ray::ColliderFact>("RayIAColliderFact");
    createFactory<ray::MovementFact>("MovementFact");
    createFactory<ray::BillBoardFact>("BillBoardFact");
    createFactory<ray::MusicFact>("MusicFact");
    createFactory<ray::AudioFact>("AudioFact");

    jsnp::Data data("resources/save/GameSetting.json");

    Map map(MapType::Square, 13, 13, 5, 1);
    map.apply_procedural(2);
    for (int i = 0; i != 10; i++)
        map.apply_player(data()["NbrPlayer"].second.value<int>(), 3);
    setLayer("CameraFact", 0);
    setLayer("SkyboxFact", 1);
    setLayer("MeshFact", 2);
    setLayer("ColliderFact", 3);
    setLayer("PlayerColliderFact", 3);
    setLayer("IAColliderFact", 3);
    setLayer("MovementFact", 4);
    setLayer("TransformFact", 5);
    setLayer("ScriptFact", 6);
    setLayer("SpriteFact", 7);
    setLayer("BillBoardFact", 8);
    setLayer("TextFact", 9);

    createEntity("Map");
    createEntity("GameManager");
    createEntity("MainCamera");
    createEntity("PauseManager");
    createEntity("SkyBox").createComponent<ray::Skybox>("SkyboxFact");

    scriptFact.addScript<GameManager>("GameManager");
    scriptFact.insertComponent<PauseManager>("PauseManager");
    auto& mapScript = dynamic_cast<MapGenerator&>(scriptFact.addScript<MapGenerator>("Map"));
    if (Main::loadMode == NEW_GAME)
        mapScript.generateMap(map.get_Map_data().map);
    else {
        LoadManager load;
        load.loadGame("resources/save/save.json", *this);
    }
    
    scriptFact.addScript<MyCamera>("MainCamera");

    auto& ground = createEntity("Ground");
    auto& trans_ground = ground.createComponent<ray::Transform>("TransformFact");
    trans_ground.setPosition(-7, -1, 6);
    trans_ground.setScale(5, 5, 5);
    ground.createComponent<ray::Mesh>("MeshFact").setModel("Ground").setTexture("Ground");
    SaveManager save(*this);
}

void Main::onUpdate()
{}

void Main::onUnload()
{}