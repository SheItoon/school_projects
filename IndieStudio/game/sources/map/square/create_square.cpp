/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** create_square
*/

#include "map/square.hpp"

std::vector<std::string> create_map_square(int size)
{
    std::vector<std::string> map;
    std::string tmp;

    tmp.clear();
    for (int y = 0; y < size+2; y++)
        tmp.append("*");
    tmp.append("\n");
    map.emplace_back(tmp);

    for (int x = 0; x < size; x++) {
        tmp.clear();
        tmp.append("*");
        for (int y = 0; y < size; y++)
            tmp.append(" ");
        tmp.append("*\n");
        map.emplace_back(tmp);
    }
    tmp.clear();
    for (int y = 0; y < size+2; y++)
        tmp.append("*");
    tmp.append("\n");
    map.emplace_back(tmp);


    return map;
}