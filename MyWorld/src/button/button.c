/*
** EPITECH PROJECT, 2019
** button.c
** File description:
** do you need a button?
*/

#include "my_world.h"

void check_button(sfVector2i position, data_game *data)
{
    button_t *actual = data->button;
    sfVector2f pixel_pos;
    sfFloatRect rect;

    pixel_pos = sfRenderWindow_mapPixelToCoords(data->window, position,
                                                data->interface_view);
    while (actual) {
        rect = sfSprite_getGlobalBounds(actual->idle);
        if (pixel_pos.x < rect.left + rect.width && pixel_pos.x > rect.left &&
            pixel_pos.y < rect.top + rect.height && pixel_pos.y > rect.top) {
            if ((actual->tag == B_MENU && data->state != MENU) ||
                (actual->tag == B_GAME && data->state != GAME))
                return;
            actual->pressed = 1;
            actual->clicked = 1;
            if (actual->action)
                (*actual->action)(data);
            break;
        }
        actual = actual->next;
    }
}

void destroy_button(data_game *data)
{
    button_t *actual = data->button;
    button_t *delete = NULL;

    while (actual) {
        sfSprite_destroy(actual->idle);
        sfSprite_destroy(actual->help_sprite);
        sfText_destroy(actual->title);
        sfText_destroy(actual->help_text);
        delete = actual;
        actual = actual->next;
        free(delete);
    }
    data->button = NULL;
}

void button_set_other_tex(data_game *data, char *name, sfTexture *hover,
        sfTexture *press)
{
    button_t *button = data->button;

    while (button) {
        if (compare(name, button->name)) {
            button->hover = hover;
            button->press = press;
            return;
        }
        button = button->next;
    }
    write(2, "Button not found\n", 17);
}

void button_set_press_position(data_game *data, char *name, sfVector2f new_pos)
{
    button_t *button = data->button;
    sfVector2f somme_pos = {0, 0};

    while (button) {
        if (compare(name, button->name)) {
            somme_pos.x = button->position.x + new_pos.x;
            somme_pos.y = button->position.y + new_pos.y;
            sfSprite_setPosition(button->idle, somme_pos);
            button_set_text_pos(data, name, (sfVector2f) {button->text_pos.x,
                                                          button->text_pos.y +
                                                          new_pos.y}, 0);
        }
        button = button->next;
    }
}

void button_set_text(data_game *data, char *name, char *title)
{
    button_t *actual = data->button;

    while (actual) {
        if (compare(name, actual->name)) {
            sfText_setString(actual->title, title);
        }
        actual = actual->next;
    }
}
