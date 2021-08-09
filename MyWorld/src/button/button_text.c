/*
** EPITECH PROJECT, 2019
** button_text.c
** File description:
** 
*/

#include "my_world.h"

void button_set_text_pos(data_game *data, char *name, sfVector2f pos, int save)
{
    button_t *actual = data->button;
    sfVector2f position = {0, 0};

    while (actual) {
        if (compare(name, actual->name)) {
            position.x = actual->position.x + pos.x;
            position.y = actual->position.y + pos.y;
            if (save)
                actual->text_pos = (sfVector2f) {pos.x, pos.y};
            sfText_setPosition(actual->title, position);
            return;
        }
        actual = actual->next;
    }
}

void button_add_text(data_game *data, char *name, char *title)
{
    button_t *actual = data->button;
    sfVector2f scale = {0.7f, 0.7f};
    sfVector2f pos = {0, 0};

    while (actual) {
        if (compare(name, actual->name)) {
            actual->title = sfText_create();
            pos.x += actual->position.x;
            pos.y += actual->position.y;
            sfText_setString(actual->title, title);
            sfText_setFont(actual->title, data->font);
            sfText_setPosition(actual->title, pos);
            sfText_setScale(actual->title, scale);
            return;
        }
        actual = actual->next;
    }
}