/*
** EPITECH PROJECT, 2019
** how_to_play.c
** File description:
** 
*/

#include "my_world.h"

void create_button_how(data_game *data)
{
    add_button(data, (sfVector2f) {10, 120}, data->textures->button,
               "button_help");
    button_add_action(data, "button_help", &set_menu);
    button_add_text(data, "button_help", "Exit");
    button_set_text_pos(data, "button_help", (sfVector2f) {15, 30}, 1);
    button_set_tag(data, "button_help", B_HELP);
    button_set_other_tex(data, "button_help", data->textures->button_hover,
                         data->textures->button_press);

}

void how_to_play(data_game *data)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(data->window) &&
           data->state == HELP) {
        sfRenderWindow_clear(data->window, sfBlue);
        input(data);
        handle_event(data, event);
        sfRenderWindow_drawSprite(data->window, data->sprites->font, NULL);
        sfRenderWindow_drawSprite(data->window, data->sprites->help, NULL);
        draw_button(data, B_HELP);
        sfRenderWindow_display(data->window);
    }
}