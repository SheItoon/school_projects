/*
** EPITECH PROJECT, 2019
** draw_sprite.c
** File description:
** draw EVERY sprite
*/

#include "my_world.h"

void display_sprite(data_game *data)
{
    sfRenderWindow_drawSprite(data->window, data->sprites->font, NULL);
}