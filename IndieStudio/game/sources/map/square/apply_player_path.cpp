/*
** EPITECH PROJECT, 2021
** Delivery
** File description:
** apply_player_path
*/

#include "map/square.hpp"

data_map apply_player_path(data_map data)
{
    int x = 1, y = 1, nbr_space = 0, rdn = 0, result = 0;
    std::random_device r;
    std::default_random_engine e1(r());
    std::string tmp;
    std::vector<std::pair<int, int>> coord;
    std::vector<int> path;

    nbr_space = find_space(data);
    data = remove_b(data);
    data = apply_E(data);
    while (nbr_space != 0) {
        for (int i = 1; i != data.size_x/2+2; i++)
            for (int j = 1; j != data.size_y+1; j++)
                if (data.map[i][j] == ' ' || data.map[i][j] == 'p') {
                    x = i;
                    y = j;
                    j = data.size_y;
                    i = data.size_x/2+1;
                }
    
    nbr_space = find_space(data);
    data.map[x].replace(y, 1, "N");
    data.map[x].replace(data.size_y-y+1, 1, "N");
    data.map[data.size_x-x+1].replace(y, 1, "N");
    data.map[data.size_x-x +1].replace(data.size_y-y+1, 1, "N");
    while (data.map[x][y] != 'N' || (data.map[x-1][y] != 'E' && data.map[x+1][y] != 'E' && data.map[x][y-1] != 'E' && data.map[x][y+1] != 'E')) {
        rdn = 0;
        path.clear();
        if ((data.map[x][y+1] == '*' || data.map[x][y+1] == ' ') && y+1 != data.size_y+1) {
            rdn ++;
            path.push_back(1);
        }
        if ((data.map[x][y-1] == '*' || data.map[x][y-1] == ' ') && y-1 != 0) {
            rdn ++;
            path.push_back(2);
        }
        if ((data.map[x+1][y] == '*' || data.map[x+1][y] == ' ') && x+1 != data.size_x+1) {
            rdn ++;
            path.push_back(3);
        }
        if ((data.map[x-1][y] == '*' || data.map[x-1][y] == ' ') && x-1 != 0) {
            rdn ++;
            path.push_back(4);
        }
        if (rdn == 0)
            rdn++;
        std::uniform_int_distribution<int> uniform_dist(1, rdn);
        result = uniform_dist(e1);
        if (rdn != 0) {
            for (int i = 0; i != result - 1; i++){
                path.pop_back();
            }
            if (path.size() == 0 || path[path.size() - 1] == 0)
               break;
            switch (path[path.size() - 1]) {
            case 1:
                y++;
                break;
            case 2:
                y--;
                break;
            case 3:
                x++;
                break;
            case 4:
                x--;
                break;
            default:
                break;
            }
        }
        data.map[x].replace(y, 1, "N");
        data.map[x].replace(data.size_y-y+1, 1, "N");
        data.map[data.size_x-x+1].replace(y, 1, "N");
        data.map[data.size_x-x +1].replace(data.size_y-y+1, 1, "N");
    }
    data = apply_E(data);
    }
    data = apply_E(data);
    for (int i = 1; i != data.size_x+1; i++)
        for (int j = 1; j != data.size_y+1; j++)
            if (data.map[i][j] == 'E')
                data.map[i].replace(j, 1, " ");
    return data;
}
