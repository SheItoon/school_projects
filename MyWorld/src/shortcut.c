/*
** EPITECH PROJECT, 2019
** shortcut.c
** File description:
** 
*/

#include "my_world.h"

void shortcut(data_game *data)
{
    if (data->state == MENU)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyR))
        reset_map(data);
    if (sfKeyboard_isKeyPressed(sfKeyI))
        increase_size(data);
    if (sfKeyboard_isKeyPressed(sfKeyK))
        decrease_size(data);
}
