/*
** EPITECH PROJECT, 2019
** drawn_effect_zone.c
** File description:
** 
*/

#include "my_world.h"

void draw_circle(data_game *data, slider_t *slider, sfVector2f pixel_pos,
                 sfVector2i mouse_pos)
{
    sfCircleShape *circle;
    sfRenderStates state = {sfBlendAlpha, sfTransform_Identity, NULL, NULL};

    if (compare("slider_effect", slider->name)) {
        pixel_pos.x = sfRenderWindow_mapPixelToCoords(data->window, mouse_pos,
                                                      data->interface_view).x -
                      ((5 + slider->value * 15) * 3);
        pixel_pos.y = sfRenderWindow_mapPixelToCoords(data->window, mouse_pos,
                                                      data->interface_view).y -
                      ((5 + slider->value * 15) * 3);
        circle = sfCircleShape_create();
        sfCircleShape_setPosition(circle, pixel_pos);
        sfCircleShape_setFillColor(circle, (sfColor) {255, 0, 0, 100});
        sfCircleShape_setRadius(circle, 5 + slider->value * 15);
        sfCircleShape_setScale(circle, (sfVector2f) {3, 3});
        sfRenderWindow_drawCircleShape(data->window, circle, &state);
        sfCircleShape_destroy(circle);
        return;
    }
}

void draw_selection(data_game *data)
{
    slider_t *slider = data->slider;
    sfVector2f pixel_pos = {-1, -1};
    sfVector2i mouse_pos;

    sfRenderWindow_setView(data->window, data->interface_view);
    if (data->selection != CORNER)
        return;
    mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    while (slider) {
        draw_circle(data, slider, pixel_pos, mouse_pos);
        slider = slider->next;
    }
}
