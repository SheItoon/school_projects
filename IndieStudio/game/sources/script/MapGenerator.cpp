/*
** EPITECH PROJECT, 2021
** MapGenerator.cpp
** File description:
** MapGenerator.cpp
*/

#include "factory/ScriptFact.hpp"
#include "component/components.hpp"
#include "script/MapGenerator.hpp"
#include "script/Cube.hpp"
#include "script/Mob.hpp"

static void CreateNewCube(sw::Entity& entity, int i, int j, int type)
{
    sw::Entity& new_entity = entity.m_scene.createEntity("Cube-" + std::to_string(j) + "-" + std::to_string(i));
    auto& fact = new_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");

    switch (type) {
        case 0:
            fact.addScript<Cube>(new_entity.m_name, Cube::Type::BREAKABLE);
            break;
        case 1:
            fact.addScript<Cube>(new_entity.m_name, Cube::Type::UNBREAKABLE);
            break;
    }
}

std::vector<std::string>& MapGenerator::get_map()
{
    return (m_map);
}

std::vector<sw::Vector3i> MapGenerator::get_player_pos()
{
    return(m_player_pos);
}

std::vector<std::string> MapGenerator::get_player_name()
{
    return(m_player_name);
}

void MapGenerator::update()
{
    jsnp::Data data("resources/save/GameSetting.json");
    int player = 0;
    int type = -1;

    while (player < m_nbr_player) {
        type = data()["Player_" + std::to_string(player + 1)].second.value<jsnp::Object>()["type"].second.value<int>();
        if (type == 0) {
            m_player_pos[player].x = std::lround(m_entity.m_scene.getEntity("Player" + std::to_string(player + 1)).getComponent<ray::Transform>("TransformFact").getPosition().x);
            m_player_pos[player].z = std::lround(m_entity.m_scene.getEntity("Player" + std::to_string(player + 1)).getComponent<ray::Transform>("TransformFact").getPosition().z);
        }
        if (type == 1) {
            m_player_pos[player].x = std::lround(m_entity.m_scene.getEntity("AI" + std::to_string(player + 1)).getComponent<ray::Transform>("TransformFact").getPosition().x);
            m_player_pos[player].z = std::lround(m_entity.m_scene.getEntity("AI" + std::to_string(player + 1)).getComponent<ray::Transform>("TransformFact").getPosition().z);
        }
        player++;
    }
}

void MapGenerator::addBombeMap(ray::Transform trans)
{
    m_map.at(std::lround(trans.getPosition().x)*-1).replace(std::lround(trans.getPosition().z), 1, "O");
}

void MapGenerator::generateCharacter(int nbrPlayer, sw::ScriptFact &fact, jsnp::Data &data, int entityType, int i, int j)
{
    switch (entityType) {
        case 0:
            m_player_pos.push_back(sw::Vector3i{i, 0, j});
            m_player_name.push_back("Player" + std::to_string(nbrPlayer + 1));
            m_entity.m_scene.createEntity("Player" + std::to_string(nbrPlayer + 1));
            dynamic_cast<Player&>(fact.addScript<Player>("Player" + std::to_string(nbrPlayer + 1))).setPlayer(nbrPlayer).setSkin(data()["Player_" + std::to_string(nbrPlayer + 1)].second.value<jsnp::Object>()["skin"].second.value<std::string>());
            m_entity.m_scene.getEntity("Player" + std::to_string(nbrPlayer + 1)).getComponent<ray::Transform>("TransformFact").setPosition(sw::Vector3f{static_cast<float>(-i * 1), 0, static_cast<float>(j * 1)});
            break;
        case 1:
            m_player_pos.push_back(sw::Vector3i{i, 1, j});
            m_player_name.push_back("AI" + std::to_string(nbrPlayer + 1));
            m_entity.m_scene.createEntity("AI" + std::to_string(nbrPlayer + 1));
            dynamic_cast<Mob&>(fact.addScript<Mob>("AI" + std::to_string(nbrPlayer + 1))).setPlayer(nbrPlayer).setSkin(data()["Player_" + std::to_string(nbrPlayer + 1)].second.value<jsnp::Object>()["skin"].second.value<std::string>());
            m_entity.m_scene.getEntity("AI" + std::to_string(nbrPlayer + 1)).getComponent<ray::Transform>("TransformFact").setPosition(sw::Vector3f{static_cast<float>(-i * 1), 0, static_cast<float>(j * 1)});
            break;
        case 2:
        default:
            break;
    }
}

void MapGenerator::generateMap(std::vector<std::string> map)
{
    int nbrPlayer = 0;
    auto& fact = m_entity.m_scene.getFactory<sw::ScriptFact>("ScriptFact");
    jsnp::Data data("resources/save/GameSetting.json");

    for (int i = 0; i < map.size(); i++)
        for (int j = 0; j < map.at(i).length(); j++)
            switch (map.at(i).at(j)) {
                case '*':
                    CreateNewCube(m_entity, j, i, 1);
                    break;
                case 'b':
                    CreateNewCube(m_entity, j, i, 0);
                    break;
                case 'p':
                    map.at(i).replace(j, 1, " ");
                    generateCharacter(nbrPlayer, fact, data, data()["Player_" + std::to_string(nbrPlayer + 1)].second.value<jsnp::Object>()["type"].second.value<int>(), j, i);
                    nbrPlayer += 1;
                    m_nbr_player = nbrPlayer;
                    break;
                default:
                    break;
            }
    m_map = map;
}