/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** square
*/

#ifndef SQUARE_HPP_
#define SQUARE_HPP_
#include "Map.hpp"

std::vector<std::string> proced_map_square_odd(std::vector<std::string> map, int size, int difficulty);
std::vector<std::string> proced_map_square_pair(std::vector<std::string> map, int size, int difficulty);
std::vector<std::string> basic_map_square(std::vector<std::string> map);
data_map apply_E(data_map data);
data_map remove_b(data_map data);
int find_space(data_map data);
data_map apply_player_path(data_map data);
data_map apply_player(data_map data, int nbr);
#endif /* !SQUARE_HPP_ */
