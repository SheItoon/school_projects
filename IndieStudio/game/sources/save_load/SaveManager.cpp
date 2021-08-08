/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-guillaume.soisson
** File description:
** load
*/

#include "jsnp.hpp"
#include "save_load/SaveManager.hpp"
#include "SW/Scene.hpp"
#include "script/Cube.hpp"
#include "script/Player.hpp"
#include "script/Mob.hpp"
#include "component/components.hpp"
#include <iostream>

static void SaveBlocksProperties(std::string& currentString, sw::Entity& currentEntity) 
{
    if (currentEntity.isActive() == false)
        currentString.insert(0, 1, ' ');
    else {
        switch (currentEntity.getComponent<Cube>("ScriptFact").getType()) {
            case Cube::BREAKABLE:
                currentString.insert(0, 1, 'b');
                break;
            case Cube::UNBREAKABLE:
                currentString.insert(0, 1, '*');
                break;
        }
    }
}

static void SavePlayersPositions(sw::Entity& currentEntity, jsnp::Object& playerObject, std::vector<std::string>& mapVector)
{
    ray::Transform currentTransform = currentEntity.getComponent<ray::Transform>("TransformFact");
    jsnp::Object positionObject;

    auto& pos = currentTransform.getPosition();
    positionObject.emplace_back("x", std::to_string(pos.x));
    positionObject.emplace_back("y", std::to_string(pos.y));
    positionObject.emplace_back("z", std::to_string(pos.z));
    mapVector[std::lround(pos.x * -1)][std::lround(pos.z)] = 'p';
    playerObject.emplace_back("Position", positionObject);
}

static void SavePlayersStats(std::string const& currentPlayerType,
                            sw::Entity& currentEntity, 
                            jsnp::Object& playerObject)
{
    jsnp::Object statsObject;

    if (currentPlayerType == "Player") {
        Player& currentPlayerData = currentEntity.getComponent<Player>("ScriptFact");
        statsObject.emplace_back("CurrentBombs", currentPlayerData.getBomb());
        statsObject.emplace_back("MaxBombs", currentPlayerData.getMax());
        statsObject.emplace_back("Speed", std::to_string(currentPlayerData.getSpeed()));
        statsObject.emplace_back("Range", currentPlayerData.getRange());
    }
    else {
        Mob& currentPlayerData = currentEntity.getComponent<Mob>("ScriptFact");
        statsObject.emplace_back("CurrentBombs", currentPlayerData.getBomb());
        statsObject.emplace_back("MaxBombs", currentPlayerData.getMax());
        statsObject.emplace_back("Speed", std::to_string(currentPlayerData.getSpeed()));
        statsObject.emplace_back("Range", currentPlayerData.getRange());
    }
    playerObject.emplace_back("Stats", statsObject);    
}

int SaveManager::getMapSize() const
{
    int size = 0;

    for (auto& entity : entitiesMap()) {
        if (entity.first.rfind("Cube-0", 0) != std::string::npos)
            size++;
    }
    return size - 1;
}

void SaveManager::saveMap()
{
    int size = getMapSize();

    for (int i = 0; i <= size; i++) {
        std::string currentString;
        for (int j = 0; j <= size; j++) {
            std::string currentEntityName = std::string("Cube-" + std::to_string(i) + "-" + std::to_string(j));
            if (entitiesMap().find(currentEntityName) != entitiesMap().end()) {
                sw::Entity& currentEntity = static_cast<sw::Entity&>(*entitiesMap()[currentEntityName]);
                SaveBlocksProperties(currentString, currentEntity);
            }
            else
                currentString.insert(0, 1, ' ');
        }
        m_mapVector.emplace_back(currentString);
    }
}

void SaveManager::savePlayers()
{
    jsnp::Object playersList;

    for (int i = 1; i <= 4; i++) {
        jsnp::Object playerObject;
        std::string currentPlayerType;
        if (entitiesMap().find(std::string("Player" + std::to_string(i))) != entitiesMap().end())
            currentPlayerType = "Player";
        else if (entitiesMap().find(std::string("AI" + std::to_string(i))) != entitiesMap().end())
            currentPlayerType = "AI";
        else
            continue;
        currentPlayerType == "Player" ? playerObject.emplace_back("IsAI", false) : playerObject.emplace_back("IsAI", true);

        sw::Entity& currentEntity = static_cast<sw::Entity&>(*entitiesMap()[currentPlayerType + std::to_string(i)]);
        playerObject.emplace_front("EntityName", currentEntity.m_name);
        playerObject.emplace_back("IsActive", currentEntity.isActive());
        SavePlayersPositions(currentEntity, playerObject, m_mapVector);
        SavePlayersStats(currentPlayerType, currentEntity, playerObject);
        playersList.emplace_back(std::string("Player" + std::to_string(i)), playerObject);
    }
    m_saveData().emplace_back("Players", playersList);
}

void SaveManager::saveGame() 
{
    saveMap();
    savePlayers();

    jsnp::Array mapData;
    for (auto& line : m_mapVector) {
        mapData.emplace_back(line);
    }
    m_saveData().emplace_front("Map", mapData);

    m_saveData.save("resources/save/save.json");
}

SaveManager::SaveManager(sw::AScene& scene)
{
    m_entitiesMap.emplace(scene.getEntities());
    saveGame();
}