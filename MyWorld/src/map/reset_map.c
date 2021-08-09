/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main file of the program
*/

#include "my_world.h"

int **create_default_map(data_game *data)
{
    int **default_map = malloc(sizeof(int *) * (data->map_y + 1));

    for (int y = 0; y < data->map_y; y++) {
        default_map[y] = malloc(sizeof(int) * (data->map_x + 1));
        for (int x = 0; x < data->map_x; x++) {
            default_map[y][x] = 00;
            default_map[y][x + 1] = 00;
        }
        default_map[y + 1] = NULL;
    }
    return (default_map);
}

void free_map(data_game *data)
{
    if (!data->map)
        return;
    for (int y = 0; y < data->map_y - 1; y++)
        free(data->map[y]);
    free(data->map);
}

void reset_map(data_game *data)
{
    free_map(data);
    data->loader.toload++;
    data->map = create_2d_map(create_default_map(data), data);
    data->loader.toload++;
    data->cam.default_view = sfRenderWindow_getDefaultView(data->window);
    data->loader.toload++;
    data->cam.camera = sfView_copy(sfRenderWindow_getDefaultView(data->window));
    data->loader.toload++;
    sfView_setCenter(data->cam.camera, (sfVector2f) {data->winsize_f.x / 2,
                data->winsize_f.y / 2});
    data->loader.toload++;
    data->cam.factor = 1;
    data->loader.toload++;
}
