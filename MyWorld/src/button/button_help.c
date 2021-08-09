/*
** EPITECH PROJECT, 2019
** button_help.c
** File description:
** 
*/

#include "my_world.h"

void button_add_text_box(data_game *data, char *name, sfTexture *texture,
                         sfVector2f scale)
{
    button_t *button = data->button;

    while (button) {
        if (compare(button->name, name)) {
            if (!button->help_sprite)
                button->help_sprite = sfSprite_create();
            sfSprite_setTexture(button->help_sprite, texture, sfTrue);
            sfSprite_setScale(button->help_sprite, scale);
            return;
        }
        button = button->next;
    }
}

void button_add_text_box_message(data_game *data, char *name, char *text)
{
    button_t *button = data->button;

    while (button) {
        if (compare(button->name, name)) {
            if (!button->help_text)
                button->help_text = sfText_create();
            sfText_setFont(button->help_text, data->font);
            sfText_setScale(button->help_text, (sfVector2f) {0.5f, 0.5f});
            sfText_setString(button->help_text, text);
            return;
        }
        button = button->next;
    }
}

void
set_up_help_pos(button_t *button, sfFloatRect txt, sfFloatRect sprite, int y)
{
    sfVector2f pos;
    if (y == 1) {
        pos.x = button->position.x;
        pos.y = button->position.y - sprite.height - 10;
        sfSprite_setPosition(button->help_sprite, pos);
        pos.y = button->position.y - txt.height - 15;
        sfText_setPosition(button->help_text, pos);
    } else if (y == -1) {
        pos.x = button->position.x;
        pos.y = button->position.y + sprite.height + 10;
        sfSprite_setPosition(button->help_sprite, pos);
        pos.y = button->position.y + txt.height + 15;
        sfText_setPosition(button->help_text, pos);
    }
}

void
set_right_help_pos(button_t *button, sfFloatRect txt, sfFloatRect sprite, int x)
{
    sfVector2f pos;

    if (x == 1) {
        pos.x = button->position.x - sprite.width - 10;
        pos.y = button->position.y;
        sfSprite_setPosition(button->help_sprite, pos);
        pos.x = button->position.x - txt.width - 15;
        sfText_setPosition(button->help_text, pos);
    } else if (x == -1) {
        pos.x = button->position.x + (float) button->rect.width * 2 + 10;
        pos.y = button->position.y;
        sfSprite_setPosition(button->help_sprite, pos);
        pos.x = button->position.x + (float) button->rect.width * 2 + 15;
        sfText_setPosition(button->help_text, pos);
    }
}

void button_help_display(data_game *data, char *name, sfVector2i pos)
{
    button_t *button = data->button;
    sfFloatRect rect_sprite;
    sfFloatRect rect_text;

    while (button) {
        if (compare(button->name, name)) {
            rect_sprite = sfSprite_getGlobalBounds(button->help_sprite);
            rect_text = sfText_getGlobalBounds(button->help_text);
            set_up_help_pos(button, rect_text, rect_sprite, pos.y);
            set_right_help_pos(button, rect_text, rect_sprite, pos.x);
        }
        button = button->next;
    }
}