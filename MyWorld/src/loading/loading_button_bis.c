/*
** EPITECH PROJECT, 2019
** loading_button_bis.c
** File description:
** 
*/

#include "my_world.h"

void set_hover_tex(data_game *data)
{
    button_set_other_tex(data, "button_tile", data->textures->button_hover, data->textures->button_press);
    button_set_other_tex(data, "button_up-down", data->textures->button_hover, data->textures->button_press);
    button_set_other_tex(data, "button_corner", data->textures->button_hover, data->textures->button_press);
    button_set_other_tex(data, "button_reset", data->textures->button_hover, data->textures->button_press);
    button_set_other_tex(data, "button_menu", data->textures->button_hover, data->textures->button_press);
    button_set_other_tex(data, "button_paint", data->textures->button_hover, data->textures->button_press);
}
