/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/

#include "my_world.h"
#include "get_next_line.h"

inline void set_play(data_game *data)
{
    data->cam.camera = sfView_copy(data->cam.default_view);
    data->save.has_loaded = 1;
    reset_map(data);
    data->state = GAME;
}

inline void set_menu(data_game *data)
{
    data->cam.camera = sfView_copy(data->cam.default_view);
    reset_map(data);
    data->save.has_loaded = 0;
    data->state = MENU;
}

inline void set_exit(data_game *data)
{
    data->state = OVER;
    sfRenderWindow_close(data->window);
}

void display_how_to_play(data_game *data)
{
    data->state = HELP;
}

inline void set_load(data_game *data)
{
    int fd;
    char *tmp = NULL;
    int y = get_row("map.legend");
    sfVector2f yee;

    fd = open("map.legend", O_RDONLY);
    if (fd == -1)
        return;
    tmp = get_next_line(fd);
    data->map_x = my_getnbr(tmp);
    data->map_y = my_getnbr(tmp), free(tmp);
    data->map = malloc(sizeof(sfVector2f *) * (data->map_y + 1));
    for (int y = 0; y < data->map_y; y++) {
        data->map[y] = malloc(sizeof(sfVector2f) * (data->map_x));
        for (int x = 0; x < data->map_x; x++) {
            yee = get_vector(fd, data);
            data->map[y][x] = yee;
        }
    }
    data->state = GAME;
    data->save.has_loaded = 1, close(fd), my_world(data);
}
