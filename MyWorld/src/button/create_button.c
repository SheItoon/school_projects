/*
** EPITECH PROJECT, 2019
** create_button.c
** File description:
** create any button
*/

#include "my_world.h"

void button_add_action(data_game *data, char *name, void (*action)(data_game *))
{
    button_t *actual = data->button;

    while (actual) {
        if (compare(name, actual->name)) {
            actual->action = action;
            return;
        }
        actual = actual->next;
    }
}

void set_default_value_button(button_t *button)
{
    button->help_sprite = NULL;
    button->title = NULL;
    button->help_text = NULL;
    button->action = NULL;
    button->next = NULL;
}

void add_button(data_game *data, sfVector2f position, sfTexture *texture,
                char *name)
{
    button_t *button = malloc(sizeof(button_t));
    button_t *actual = data->button;

    while (actual && actual->next) {
        if (compare(name, actual->name))
            write(2, "Button already exist\n", 21);
        actual = actual->next;
    }
    set_default_value_button(button);
    button->name = name;
    button->idle = sfSprite_create();
    button->stand = texture;
    button->press = NULL;
    button->hover = NULL;
    button->tag = B_DEFAULT;
    sfSprite_setTexture(button->idle, button->stand, sfTrue);
    button->rect = sfSprite_getTextureRect(button->idle);
    button->position = position;
    button->pressed = 0;
    button->clicked = 0;
    button->time = 0;
    if (actual)
        actual->next = button;
    else
        data->button = button;
}

void button_set_tag(data_game *data, char *name, button_tag_t tag)
{
    button_t *button = data->button;

    while (button) {
        if (compare(name, button->name)) {
            button->tag = tag;
            return;
        }
        button = button->next;
    }
}

void button_set_texture(data_game *data, sfTexture *texture, char *name)
{
    button_t *actual = data->button;

    while (actual) {
        if (compare(name, actual->name)) {
            sfSprite_setTexture(actual->idle, texture, sfTrue);
            actual->rect = sfSprite_getTextureRect(actual->idle);
            return;
        }
        actual = actual->next;
    }
}