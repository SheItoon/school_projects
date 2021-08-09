/*
** EPITECH PROJECT, 2019
** button_action.c
** File description:
** action for some button
*/

#include "my_world.h"

void change_select_corner(data_game *data)
{
    data->selection = CORNER;
}

void change_select_tile(data_game *data)
{
    data->selection = TILE;
}

void change_dir(data_game *data)
{
    if (data->direction == UP) {
        data->direction = DOWN;
        button_set_text(data, "button_up-down", "Down");
    } else if (data->direction == DOWN){
        data->direction = UP;
        button_set_text(data, "button_up-down", "Up");
    }
}