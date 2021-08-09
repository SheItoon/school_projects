/*
** EPITECH PROJECT, 2019
** slider_destroy.c
** File description:
** 
*/

#include "my_world.h"

void slider_destroy(data_game *data)
{
    slider_t *slider = data->slider;
    slider_t *destroy = NULL;

    while (slider) {
        sfSprite_destroy(slider->slider);
        sfSprite_destroy(slider->cursor);
        destroy = slider;
        slider = slider->next;
        free(destroy);
    }
}