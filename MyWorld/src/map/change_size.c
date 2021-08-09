/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#include "my_world.h"

void increase_size(data_game *data)
{
    sfVector2f **new_map = malloc(sizeof(sfVector2f *) * (data->map_y + 2));
    int x = 0;
    int y = 0;

    if (data->map_y >= 14 && data->map_x >= 14)
        return;
    for (y = 0; y < data->map_y; y++) {
        new_map[y] = malloc(sizeof(sfVector2f) * (data->map_x + 1));
        for (x = 0; x < data->map_x; x++)
            new_map[y][x] = data->map[y][x];
        new_map[y][x] = project_iso_point(x, y, 0);
    }
    new_map[y] = malloc(sizeof(sfVector2f) * (data->map_x + 2));
    for (int i = 0; i <= data->map_x; i++)
        new_map[y][i] = project_iso_point(i, y, 0);
    data->map_x += 1;
    data->map_y += 1;
    free_map(data);
    data->map = new_map;
}

void decrease_size(data_game *data)
{
    sfVector2f **new_map = malloc(sizeof(sfVector2f *) * (data->map_y - 1));

    if (data->map_x <= 2 && data->map_y <= 2)
        return;
    for (int y = 0; y < data->map_y - 1; y++) {
        new_map[y] = malloc(sizeof(sfVector2f) * (data->map_x - 1));
        for (int x = 0; x < data->map_x - 1; x++)
            new_map[y][x] = data->map[y][x];
    }
    free_map(data);
    data->map_x -= 1;
    data->map_y -= 1;
    data->map = new_map;
}