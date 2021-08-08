/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** apply_player
*/

#include "map/square.hpp"

data_map apply_player(data_map data, int nbr)
{

    bool s = 1;
    int advancement = 1;
    if (nbr == 0)
        data.nbr_max_player = ((data.size_x-1)/4)*4;
    else
        data.nbr_max_player = nbr;
    if (data.size_x <= 4 && data.size_x >= 2)
        data.nbr_max_player = 2;
    data.nbr_max_player_save = data.nbr_max_player;
    if (data.nbr_max_player == 2) {
        data.map[1].replace(1,1, "p");
        data.map[2].replace(1,1, " ");
        data.map[1].replace(2,1, " ");
        data.map[data.size_y].replace(data.size_x,1, "p");
        data.map[data.size_y-1].replace(data.size_x,1, " ");
        data.map[data.size_y].replace(data.size_x-1,1, " ");
        data.nbr_max_player = 0;
    }
    else {
        data.map[data.size_y].replace(1,1, "p");
        data.map[data.size_y-1].replace(1,1, " ");
        data.map[data.size_y].replace(2,1, " ");
        data.map[1].replace(data.size_x,1, "p");
        data.map[2].replace(data.size_x,1, " ");
        data.map[1].replace(data.size_x-1,1, " ");
        data.map[data.size_y].replace(data.size_x,1, "p");
        data.map[data.size_y-1].replace(data.size_x,1, " ");
        data.map[data.size_y].replace(data.size_x-1,1, " ");
        data.map[1].replace(1,1, "p");
        data.map[2].replace(1,1, " ");
        data.map[1].replace(2,1, " ");
        data.nbr_max_player -= 4;
    }
    while (data.nbr_max_player > 0) {
        if (s) {
            data.map[data.size_y-(4*advancement)].replace(1,1, "p");
            data.map[data.size_y-1-(4*advancement)].replace(1,1, " ");
            data.map[data.size_y+1-(4*advancement)].replace(1,1, " ");
            data.map[1+(4*advancement)].replace(data.size_x,1, "p");
            data.map[2+(4*advancement)].replace(data.size_x,1, " ");
            data.map[0+(4*advancement)].replace(data.size_x,1, " ");
            data.map[data.size_y].replace(data.size_x-(4*advancement),1, "p");
            data.map[data.size_y].replace(data.size_x+1-(4*advancement),1, " ");
            data.map[data.size_y].replace(data.size_x-1-(4*advancement),1, " ");
            data.map[1].replace(1+(4*advancement),1, "p");
            data.map[1].replace(0+(4*advancement),1, " ");
            data.map[1].replace(2+(4*advancement),1, " ");
            data.nbr_max_player -= 4;
            s = !s;
        }
        if (data.nbr_max_player == 0)
            break;
        if (!s) {
            data.map[data.size_y].replace(1+(4*advancement),1, "p");
            data.map[data.size_y].replace(0+(4*advancement),1, " ");
            data.map[data.size_y].replace(2+(4*advancement),1, " ");
            data.map[1].replace(data.size_x-(4*advancement),1, "p");
            data.map[1].replace(data.size_x+1-(4*advancement),1, " ");
            data.map[1].replace(data.size_x-1-(4*advancement),1, " ");
            data.map[data.size_y-(4*advancement)].replace(data.size_x,1, "p");
            data.map[data.size_y-1-(4*advancement)].replace(data.size_x,1, " ");
            data.map[data.size_y+1-(4*advancement)].replace(data.size_x,1, " ");
            data.map[1+(4*advancement)].replace(1,1, "p");
            data.map[2+(4*advancement)].replace(1,1, " ");
            data.map[0+(4*advancement)].replace(1,1, " ");

            s = !s;
            advancement++;
            data.nbr_max_player -= 4;
        }
    }
    return data;
}