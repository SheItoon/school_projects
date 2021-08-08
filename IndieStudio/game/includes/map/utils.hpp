/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_
#include "Map.hpp"

data_map proced_square(data_map data);
data_map proced_circle(data_map data);
data_map proced_rectangle(data_map data);
data_map player_square(data_map data, int nbr, int pourc);
data_map player_circle(data_map data);
data_map player_rectangle(data_map data);
data_map block_square(data_map data);
data_map block_circle(data_map data);
data_map block_rectangle(data_map data);
std::vector<std::string> create_map_circle(int x, int y);
std::vector<std::string> create_map_square(int size);
std::vector<std::string> create_map_rectangle(int x, int y);
void disp_map(std::vector<std::string> map);

#endif /* !UTILS_HPP_ */
