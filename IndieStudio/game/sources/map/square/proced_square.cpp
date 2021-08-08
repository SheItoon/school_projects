/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** proced_square
*/

#include "map/square.hpp"

std::vector<std::string> basic_map_square(std::vector<std::string> map)
{
    std::string tmp;
    map.clear();
    tmp.clear();
    for (int y = 0; y < 13+2; y++)
        tmp.append("*");
    tmp.append("\n");
    map.emplace_back(tmp);

    for (int x = 0; x < 13; x++) {
        tmp.clear();
        tmp.append("*");
        for (int y = 0; y < 13; y++)
            if (y % 2)
                tmp.append("*");
            else
                tmp.append(" ");
        tmp.append("X\n");
        map.emplace_back(tmp);
    }
    tmp.clear();
    for (int y = 0; y < 13+2; y++)
        tmp.append("*");
    tmp.append("\n");
    map.emplace_back(tmp);
    return (map);
}

std::vector<std::string> proced_map_square_odd(std::vector<std::string> map, int size, int difficulty)
{
    (void) difficulty;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 1);
    std::string tmp;
    int rdn;

//    for (int x = 1; x != size+1; x++) {
//        for (int y = 1; y != size+1; y++) {
//            map[x].replace(y, 1, " ");
//        }
//    }

    for (int x = 1; x != size/2+1; x++) {
        for (int y = 1; y != size/2+1; y++) {
            rdn = uniform_dist(e1);
            if (!rdn) {
                map[x].replace(y, 1, "*");
                map[x].replace(size-y+1, 1, "*");
                map[size-x+1].replace(y, 1, "*");
                map[size-x+1].replace(size-y+1, 1, "*");
            }
        }
    }
    for (int y = 1; y != size/2+1; y++) {
        rdn = uniform_dist(e1);
        if (!rdn) {
            map[size/2+1].replace(y, 1, "*");
            map[size/2+1].replace(size-y+1, 1, "*");
        }
    }
    for (int y = 1; y != size/2+1; y++) {
        rdn = uniform_dist(e1);
        if (!rdn) {
            map[y].replace(size/2+1, 1, "*");
            map[size-y+1].replace(size/2+1, 1, "*");
        }
    }
    rdn = uniform_dist(e1);
    if (!rdn)
        map[size/2+1].replace(size/2+1, 1, "*");
    return (map);
}

std::vector<std::string> proced_map_square_pair(std::vector<std::string> map, int size, int difficulty)
{
    (void) difficulty;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, 1);
    std::string tmp;
    int rdn;

    for (int x = 1; x != size/2+1; x++) {

        for (int y = 1; y != size/2+1; y++) {
            rdn = uniform_dist(e1);
            if (!rdn) {
                map[x].replace(y, 1, "*");
                map[x].replace(size-y+1, 1, "*");
                map[size-x+1].replace(y, 1, "*");
                map[size-x+1].replace(size-y+1, 1, "*");
            }
        }
    }
    return (map);
}

data_map proced_square(data_map data)
{
    switch (data.difficulty) {
    case 0:
        data.map = basic_map_square(data.map);
        break;
    default:
        if (data.size_x % 2 && data.size_y % 2)
            data.map = proced_map_square_odd(data.map, data.size_x, data.difficulty);
        else
            data.map = proced_map_square_pair(data.map, data.size_x, data.difficulty);
        break;
    }
    return data;
}
