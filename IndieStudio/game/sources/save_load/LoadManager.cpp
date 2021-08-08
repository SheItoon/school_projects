/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-guillaume.soisson
** File description:
** LoadManager
*/

#include "save_load/LoadManager.hpp"
#include "script/MapGenerator.hpp"
#include "script/Mob.hpp"

static std::vector<std::string> GetMapVector(jsnp::Object saveObject)
{
    std::vector<std::string> mapVector;
    for (auto& line : saveObject["Map"].second.value<jsnp::Array>())
        mapVector.emplace_back(line.value<std::string>());
    return mapVector;
}

static void LoadCharacters(std::string const& currentEntityName, 
                        jsnp::Token& player, 
                        sw::ScriptFact& fact, 
                        jsnp::Object gameSettings)
{

    int playerNumber = currentEntityName.back() - '0';
    if (!player.second.value<jsnp::Object>()["IsAI"].second.value<bool>()) {
        Player& currentPlayerProperties = static_cast<Player&>(fact.addScript<Player>(currentEntityName));
        currentPlayerProperties.setPlayer(playerNumber);
        currentPlayerProperties.setSkin(gameSettings["Player_" + std::to_string(playerNumber)].second.value<jsnp::Object>()["skin"].second.value<std::string>());
        currentPlayerProperties.setRange(player.second.value<jsnp::Object>()["Stats"].second.value<jsnp::Object>()["Range"].second.value<int>());
        currentPlayerProperties.setMaxBomb(player.second.value<jsnp::Object>()["Stats"].second.value<jsnp::Object>()["MaxBombs"].second.value<int>());
        currentPlayerProperties.setSpeed(std::stof(player.second.value<jsnp::Object>()["Stats"].second.value<jsnp::Object>()["Speed"].second.value<std::string>()));
    }
    else {
        Mob& currentPlayerProperties = static_cast<Mob&>(fact.addScript<Mob>(currentEntityName));
        currentPlayerProperties.setPlayer(playerNumber);
        currentPlayerProperties.setSkin(gameSettings["Player_" + std::to_string(playerNumber)].second.value<jsnp::Object>()["skin"].second.value<std::string>());
        currentPlayerProperties.setRange(player.second.value<jsnp::Object>()["Stats"].second.value<jsnp::Object>()["Range"].second.value<int>());
        currentPlayerProperties.setMaxBomb(player.second.value<jsnp::Object>()["Stats"].second.value<jsnp::Object>()["MaxBombs"].second.value<int>());
        currentPlayerProperties.setSpeed(std::stof(player.second.value<jsnp::Object>()["Stats"].second.value<jsnp::Object>()["Speed"].second.value<std::string>()));
    } 
}

void LoadManager::loadGame(std::string const& savePath, sw::AScene& scene)
{
    jsnp::Data saveData(savePath);
    jsnp::Data gameSettings("resources/save/GameSetting.json");
    sw::Entity& mapEntity = scene.getEntity("Map");

    jsnp::Object playersObject = saveData()["Players"].second.value<jsnp::Object>();
    sw::ScriptFact& fact = scene.getFactory<sw::ScriptFact>("ScriptFact");
    for (auto& player : playersObject) {
        std::string currentEntityName = player.second.value<jsnp::Object>()["EntityName"].second.value<std::string>();
        scene.createEntity(currentEntityName);

        LoadCharacters(currentEntityName, player, fact, gameSettings());

        jsnp::Object currentPosition = player.second.value<jsnp::Object>()["Position"].second.value<jsnp::Object>();
        sw::Vector3f playerPos({std::stof(currentPosition["x"].second.value<std::string>()), 
                                std::stof(currentPosition["y"].second.value<std::string>()), 
                                std::stof(currentPosition["z"].second.value<std::string>())});
        scene.getEntity(currentEntityName).createComponent<ray::Transform>("TransformFact").setPosition(playerPos);
    }
    auto mapVector = GetMapVector(saveData());
    mapEntity.getComponent<MapGenerator>("ScriptFact").generateMap(mapVector);
}