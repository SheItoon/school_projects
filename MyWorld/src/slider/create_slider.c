/*
** EPITECH PROJECT, 2019
** create_slider.c
** File description:
** create good slider
*/

#include "my_world.h"

void add_slider(data_game *data, char *name, sfVector2f position)
{
    slider_t *new_slider = malloc(sizeof(slider_t));
    slider_t *last = data->slider;

    while (last && last->next)
        last = last->next;
    new_slider->name = name;
    new_slider->position = position;
    new_slider->pos_cursor = (int) position.y;
    new_slider->pos_x_min = (int) position.x;
    new_slider->pos_x_max = (int) position.x + 100;
    new_slider->current_pos = (int) position.x;
    new_slider->scale = 1;
    new_slider->slider = sfSprite_create();
    new_slider->cursor = sfSprite_create();
    new_slider->value = 0;
    new_slider->next = NULL;
    if (!last)
        data->slider = new_slider;
    else
        last->next = new_slider;
}

void slider_set_slider_texture(data_game *data, char *name, sfTexture *texture,
                               float scale)
{
    slider_t *slider = data->slider;

    while (slider) {
        if (compare(slider->name, name)) {
            sfSprite_setTexture(slider->slider, texture, sfTrue);
            sfSprite_setScale(slider->slider, (sfVector2f) {scale, scale});
            return;
        }
        slider = slider->next;
    }
    write(2, "ERROR: slider not found\n", 24);
}

void slider_set_cursor_texture(data_game *data, char *name, sfTexture *texture,
                               float scale)
{
    slider_t *slider = data->slider;

    while (slider) {
        if (compare(slider->name, name)) {
            sfSprite_setTexture(slider->cursor, texture, sfTrue);
            sfSprite_setScale(slider->cursor, (sfVector2f) {scale, scale});
            slider->cursor_rect = sfSprite_getLocalBounds(slider->cursor);
            slider->scale = (int) scale;
            return;
        }
        slider = slider->next;
    }
    write(2, "ERROR: slider not found\n", 24);
}

void slider_set_extreme_value(data_game *data, char *name, int min, int max)
{
    slider_t *slider = data->slider;
    sfIntRect rect;

    while (slider) {
        if (compare(slider->name, name)) {
            rect = sfSprite_getTextureRect(slider->slider);
            slider->pos_x_min = (int) slider->position.x - min;
            slider->pos_x_max = (int) slider->position.x + rect.width + max;
            return;
        }
    }
    write(2, "ERROR: slider not found\n", 24);
}

void slider_set_cursor_position(data_game *data, char *name, int y_position)
{
    slider_t *slider = data->slider;

    while (slider) {
        if (compare(slider->name, name)) {
            slider->pos_cursor = (int) slider->position.y + y_position;
            return;
        }
        slider = slider->next;
    }
    write(2, "ERROR: slider not found\n", 24);
}