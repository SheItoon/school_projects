/*
** EPITECH PROJECT, 2021
** MapGenerator.hpp
** File description:
** MapGenerator.hpp
*/

#ifndef MAPGENERATOR_HPP
#define MAPGENERATOR_HPP

#include <array>

#include "SW/Factory.hpp"
#include "component/Transform.hpp"
#include "script/Player.hpp"
#include "utils/Chrono.hpp"



class MapGenerator : public sw::Script
{
    private:
        int m_nbr_player;
        std::vector<sw::Vector3i> m_player_pos;
        std::vector<std::string> m_map;
        std::vector<std::string> m_player_name;
    public:
        using sw::Script::Script;
        ~MapGenerator() override = default;
        void update() override;
        void generateMap(std::vector<std::string> map);
        void addBombeMap(ray::Transform trans);
        void generateCharacter(int nbrPlayer, sw::ScriptFact &fact, jsnp::Data &data, int entityType, int i, int j);

        std::vector<std::string>& get_map();
        std::vector<sw::Vector3i> get_player_pos();
        std::vector<std::string> get_player_name();
};

#endif //MAPGENERATOR_HPP
