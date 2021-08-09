/*
** EPITECH PROJECT, 2019
** drawn_button_help.c
** File description:
** 
*/

#include "my_world.h"

void display_help_box(data_game *data, button_t *button)
{
    if (!button->help_sprite || !button->help_text)
        return;
    sfRenderWindow_drawSprite(data->window, button->help_sprite, NULL);
    sfRenderWindow_drawText(data->window, button->help_text, NULL);
}