/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** player_square
*/

#include "map/square.hpp"

int find_space(data_map data)
{
    int nbr = 0;
    for (int x = 1; x != data.size_x+1; x++)
        for (int y = 1; y != data.size_y+1; y++)
            if (data.map[x][y] == ' ' || data.map[x][y] == 'p')
                nbr++;
    return (nbr);
}

data_map remove_b(data_map data)
{
    for (int i = 1; i != data.size_x+1; i++)
        for (int j = 1; j != data.size_y+1; j++)
            if (data.map[i][j] == 'b')
                data.map[i].replace(j, 1, " ");
    return (data);
}

data_map apply_E(data_map data)
{
    int can = 0, x = 1, y = 1;
    std::vector<std::pair<int, int>> coord;

    for (int i = 1; i != data.size_x+1; i++)
        for (int j = 1; j != data.size_y+1; j++)
            if (data.map[i][j] == ' ' || data.map[i][j] == 'p'|| data.map[i][j] == 'N') {
                x = i;
                y = j;
                j = data.size_y;
                i = data.size_x;
            }
    while (can == 0) {
        data.map[x].replace(y, 1, "E");
        data.map[data.size_x-x+1].replace(data.size_y-y+1, 1, "E");
        data.map[x].replace(data.size_y-y+1, 1, "E");
        data.map[data.size_x-x+1].replace(y, 1, "E");
        if (data.map[x][y+1] == ' ' || data.map[x][y+1] == 'p' || data.map[x][y+1] == 'N')
            coord.push_back(std::pair<int, int>(x, y+1));
        if (data.map[x][y-1] == ' ' || data.map[x][y-1] == 'p' || data.map[x][y-1] == 'N')
            coord.push_back(std::pair<int, int>(x, y-1));
        if (data.map[x+1][y] == ' ' || data.map[x+1][y] == 'p' || data.map[x+1][y] == 'N')
            coord.push_back(std::pair<int, int>(x+1, y));
        if (data.map[x-1][y] == ' ' || data.map[x-1][y] == 'p' || data.map[x-1][y] == 'N')
            coord.push_back(std::pair<int, int>(x-1, y));
        if (coord.size() != 0) {
            x = coord[coord.size()-1].first;
            y = coord[coord.size()-1].second;
            coord.pop_back();
        }
        else
            can = 1;
    }
    return (data);
}

data_map apply_block(data_map data)
{
    for (int i = 1; i != data.size_x+1; i++) {
        for (int j = 1; j != data.size_y+1; j++) {
            if (data.map[i][j] == ' ')
                data.map[i].replace(j, 1, "b");
        }
    }
    return (data);
}

data_map remove_block(data_map data, int pourc)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, pourc);
    std::string tmp;
    int rdn = 0;

    for (int i = 1; i != data.size_x/2+1; i++) {
        for (int j = 1; j != data.size_y/2+1; j++) {
            rdn = uniform_dist(e1);
            if (data.map[i][j] == 'b' && rdn == 0) {
                data.map[data.size_y-i+1].replace(data.size_x-j+1, 1, " ");
                data.map[i].replace(j, 1, " ");
                data.map[data.size_y-i+1].replace(j, 1, " ");
                data.map[i].replace(data.size_x-j+1, 1, " ");
            }
        }
    }
    return (data);
}

data_map player_square(data_map data, int nbr, int pourc)
{
    data = apply_player(data, nbr);
    data = apply_player_path(data);
    data = apply_block(data);
    data = remove_block(data, pourc);
    data = apply_player(data, nbr);
    return (data);
}