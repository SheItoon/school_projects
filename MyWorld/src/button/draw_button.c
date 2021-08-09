/*
** EPITECH PROJECT, 2019
** draw_button.cpp
** File description:
** 
*/

#include "my_world.h"

void hover_button(data_game *data, button_t *button, sfVector2f pixel_pos,
                  sfTime time)
{
    sfFloatRect rect;

    if (!button->hover)
        return;
    rect = sfSprite_getGlobalBounds(button->idle);
    if (pixel_pos.x < rect.left + rect.width && pixel_pos.x > rect.left &&
        pixel_pos.y < rect.top + rect.height && pixel_pos.y > rect.top) {
        if (button->help_time == -1 && !button->help)
            button->help_time = time.microseconds;
        sfSprite_setTexture(button->idle, button->hover,
                            sfTrue);
        if ((time.microseconds - button->help_time) / 1000000 > 0.5f) {
            button->help = 1;
            button->help_time = -1;
            display_help_box(data, button);
        }
    } else {
        button->help_time = -1;
        button->help = 0;
    }
}

void click_button(data_game *data, button_t *button, sfTime time,
                  sfVector2f pixel_pos)
{
    float seconds = 0;

    if (!button->press)
        return;
    if (button->clicked) {
        seconds = (time.microseconds - button->time) / 1000000;
        button->clicked = (seconds > 0.1) ? 0 : 1;
        button->time = (seconds > 0.1) ? 0 : button->time;
    }
    hover_button(data, button, pixel_pos, time);
    if (button->pressed) {
        button->time = time.microseconds;
        button_set_texture(data, button->press,
                           button->name);
        button_set_press_position(data, button->name,
                                  (sfVector2f) {0, 10});
    }
}

void set_texture_button(data_game *data, button_t *button)
{
    sfVector2f scale = {2, 2};

    sfSprite_setScale(button->idle, scale);
    sfSprite_setPosition(button->idle, button->position);
    button_set_texture(data, button->stand, button->name);
    button_set_press_position(data, button->name,
                              (sfVector2f) {0, 0});
}

void draw_button(data_game *data, button_tag_t tag)
{
    button_t *button = data->button;
    sfVector2i mouse_pos;
    sfVector2f pixel_pos;
    sfTime time;

    sfRenderWindow_setView(data->window, data->interface_view);
    mouse_pos = sfMouse_getPositionRenderWindow(data->window);
    pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, mouse_pos,
                                                data->interface_view);
    time = sfClock_getElapsedTime(data->sys.clock);
    while (button) {
        if (button->tag == tag) {
            set_texture_button(data, button);
            click_button(data, button, time, pixel_pos);
            sfRenderWindow_drawSprite(data->window, button->idle, NULL);
            sfRenderWindow_drawText(data->window, button->title, NULL);
        }
        button = button->next;
    }
    sfRenderWindow_setView(data->window, data->cam.camera);
}
