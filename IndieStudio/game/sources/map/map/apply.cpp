/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** apply
*/

#include "map/Map.hpp"
#include "map/utils.hpp"

void Map::apply_procedural(int pourc)
{
    switch (m_data_map.type)
    {
    case MapType::Square:
        m_data_map = proced_square(m_data_map);
        break;
    case MapType::Rectangle:
        m_data_map = proced_rectangle(m_data_map);
        break;
    case MapType::Circle:
        m_data_map = proced_circle(m_data_map);
        break;
    default:
        break;
    }
    return;
}

void Map::apply_player(int nbr, int pourc)
{
    switch (m_data_map.type)
    {
    case MapType::Square:
        m_data_map = player_square(m_data_map, nbr, pourc);
        break;
    case MapType::Rectangle:
//        m_data_map = player_rectangle(m_data_map);
        break;
    case MapType::Circle:
//        m_data_map = player_circle(m_data_map);
        break;
    default:
        break;
    }
    return;
}

void Map::apply_block(int pourc)
{

}