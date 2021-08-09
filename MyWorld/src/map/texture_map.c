/*
** EPITECH PROJECT, 2019
** texture_map.c
** File description:
** do you want a texture?
*/

#include "my_world.h"

float difference(sfVector2f a, sfVector2f b)
{
    return ((float) (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2))));
}

sfTexture *has_snow(data_game *data, int x, int y)
{
    int snow = 0;

    snow = (data->map[y][x].y < 200) ? snow + 1 : snow;
    snow = (data->map[y][x - 1].y < 200) ? snow + 1 : snow;
    snow = (data->map[y - 1][x].y < 200) ? snow + 1 : snow;
    snow = (data->map[y - 1][x - 1].y < 200) ? snow + 1 : snow;
    if (snow >= 3)
        return (data->textures->snow);
    else
        return (data->textures->grass);
}

sfTexture *get_texture(data_game *data, int x, int y)
{
    float diff = 0;

    diff -= difference(data->map[y][x - 1], data->map[y - 1][x - 1]);
    diff -= difference(data->map[y - 1][x - 1], data->map[y - 1][x]);
    diff += difference(data->map[y - 1][x], data->map[y][x]);
    diff += difference(data->map[y][x], data->map[y][x - 1]);
    diff = (float)(abs((int)diff));
    if (diff >= 0 && diff < 10)
        return (has_snow(data, x, y));
    else if (diff >= 10 && diff < 50)
        return (data->textures->dirt);
    else
        return (data->textures->stone);
}