/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <map>
#include <cmath>

enum class MapType
{
    Square = 0,
    Rectangle = 1,
    Circle = 2,
};

struct data_map
{
    int size_x;
    int size_y;
    int difficulty;
    int nbr_player;
    int nbr_max_player;
    int nbr_max_player_save;
    MapType type;
    std::vector<std::string> map;
};

struct setting_game
{
    int player;
    int size;
};

class Map
{
    private:
        data_map m_data_map;
        setting_game m_setting;
    public:
        data_map get_Map_data();
        void set_Map_data(data_map);
        void apply_procedural(int pourc);
        void apply_player(int nbr, int pourc);
        void apply_block(int pourc);
        Map(MapType type, int x, int y, int player, int difficul);
        ~Map();
}; // class Map

#endif /* !MAP_HPP_ */
