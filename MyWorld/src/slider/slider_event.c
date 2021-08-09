/*
** EPITECH PROJECT, 2019
** slider_event.c
** File description:
** event for the slider
*/

#include "my_world.h"

void slider_get_value(slider_t *slider)
{
    slider->value = (((float)slider->current_pos - (float)slider->pos_x_min +
                              slider->cursor_rect.width / 2) /
                             (float) (slider->pos_x_max - slider->pos_x_min));
    slider->value = (slider->value < 0) ? 0 : slider->value;
    slider->value = (slider->value > 1) ? 1 : slider->value;
}

slider_t *get_slider(data_game *data, char *name)
{
    slider_t *slider = data->slider;

    while (slider) {
        if (compare(slider->name, name))
            return (slider);
        slider = slider->next;
    }
    return (NULL);
}

void slider_press_cursor(data_game *data, sfVector2i position)
{
    slider_t *slider = data->slider;
    sfVector2f pixel_pos;
    sfFloatRect rect;

    pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, position,
                                                data->interface_view);
    while (slider) {
        rect = sfSprite_getGlobalBounds(slider->cursor);
        if (pixel_pos.x < rect.left + rect.width && pixel_pos.x > rect.left &&
            pixel_pos.y < rect.top + rect.height &&
            pixel_pos.y > rect.top) {
            if (pixel_pos.x + 2 < (float)slider->pos_x_min ||
                pixel_pos.x - 2 > (float)slider->pos_x_max)
                return;
            slider->current_pos = (int)(pixel_pos.x - rect.width / 2);
            slider_get_value(slider);
            return;
        }
        slider = slider->next;
    }
}

void draw_slider(data_game *data)
{
    slider_t *slider = data->slider;
    sfVector2f cursor_pos = {0, 0};

    sfRenderWindow_setView(data->window, data->interface_view);
    while (slider) {
        cursor_pos.y = (float)slider->pos_cursor;
        cursor_pos.x = (float)slider->current_pos;
        sfSprite_setPosition(slider->slider, slider->position);
        sfSprite_setPosition(slider->cursor, cursor_pos);
        sfRenderWindow_drawSprite(data->window, slider->slider, NULL);
        sfRenderWindow_drawSprite(data->window, slider->cursor, NULL);
        slider = slider->next;
    }
    sfRenderWindow_setView(data->window, data->cam.camera);
}