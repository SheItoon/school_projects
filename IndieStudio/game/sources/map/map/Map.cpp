/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** Map
*/

#include "map/Map.hpp"
#include "map/utils.hpp"

Map::Map(MapType type, int x, int y, int player, int difficulty)
{    
    m_data_map.difficulty = difficulty;
    m_data_map.nbr_player = player;
    m_data_map.size_x = x;
    m_data_map.size_y = y;
    m_data_map.type = type;
    m_data_map.nbr_max_player = 0;
    switch (type)
    {
    case MapType::Square:
        m_data_map.map = create_map_square(x);
        break;
    case MapType::Rectangle:
        m_data_map.map = create_map_rectangle(x, y);
        break;
    case MapType::Circle:
        m_data_map.map = create_map_circle(x, y);
        break;
    default:
        break;
    }
}

Map::~Map()
{
}

void Map::set_Map_data(data_map data_map)
{
    m_data_map = data_map;
}

data_map Map::get_Map_data()
{
    return (m_data_map);
}