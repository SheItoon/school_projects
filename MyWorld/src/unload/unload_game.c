/*
** EPITECH PROJECT, 2019
** unload_sprite.c
** File description:
** 
*/

#include "my_world.h"

void unload_sprite(data_game *data)
{
    sfSprite_destroy(data->sprites->font);
    sfTexture_destroy(data->textures->font);
    sfTexture_destroy(data->textures->button);
    sfTexture_destroy(data->textures->slider);
    sfTexture_destroy(data->textures->stone);
    sfTexture_destroy(data->textures->snow);
    sfTexture_destroy(data->textures->grass);
    sfTexture_destroy(data->textures->dirt);
    sfTexture_destroy(data->textures->button_press);
    sfTexture_destroy(data->textures->button_hover);
    sfTexture_destroy(data->textures->help_box);
    sfTexture_destroy(data->textures->button_l);
    sfTexture_destroy(data->textures->button_hover_l);
    sfTexture_destroy(data->textures->button_press_l);
    free(data->sprites);
    free(data->textures);
    free(data->selected_tile);
}

void save_map(data_game *data)
{
    FILE *fd;
    char *tmp;

    if (!data->save.has_loaded)
        return;
    fd = fopen("map.legend", "w");
    tmp = get_score(data->map_x), fwrite(tmp, 1, my_strlen(tmp), fd);
    fwrite(" ", 1, 1, fd), free(tmp), tmp = get_score(data->map_x);
    fwrite(tmp, 1, my_strlen(tmp), fd), fwrite("\n", 1, 1, fd), free(tmp);
    for (int y = 0; y < data->map_y; y++)
        for (int x = 0; x < data->map_x; x++) {
            tmp = get_score((int)data->map[y][x].x + 1);
            fwrite(tmp, 1, my_strlen(tmp), fd);
            fwrite(" ", 1, 1, fd);
            free(tmp);
            tmp = get_score((int)data->map[y][x].y + 1);
            fwrite(tmp, 1, my_strlen(tmp), fd);
            if (x + 1 >= data->map_x && y + 1 < data->map_y)
                fwrite("\n\n", 1, 2, fd);
            else
                fwrite("\n", 1, 1, fd);
            free(tmp);
        }
    fclose(fd);
}

void unload_game(data_game *data)
{
    save_map(data);
    data->state = ENDGAME;
    unload_sprite(data);
    destroy_button(data);
    slider_destroy(data);
    sfClock_destroy(data->sys.clock);
    sfMutex_destroy(data->thread.lock);
    sfView_destroy(data->interface_view);
    sfImage_destroy(data->icon.image);
    sfRenderWindow_destroy(data->window);
}
