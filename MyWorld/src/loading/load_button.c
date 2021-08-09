/*
** EPITECH PROJECT, 2019
** load_button.c
** File description:
** 
*/

#include "my_world.h"

void load_some_button(data_game *data)
{
    add_button(data, (sfVector2f) {1800, 20}, data->textures->button,
               "button_reset");
    button_add_action(data, "button_reset", &reset_map);
    button_add_text(data, "button_reset", "Reset");
    button_set_text_pos(data, "button_reset", (sfVector2f) {15, 30}, 1);
    button_add_text_box(data, "button_reset", data->textures->help_box,
                        (sfVector2f) {9, 1});
    button_add_text_box_message(data, "button_reset",
                                "Reset your map (not her size!)");
    button_help_display(data, "button_reset", (sfVector2i) {1, 0});
    button_set_tag(data, "button_reset", B_GAME);
    add_button(data, (sfVector2f) {1475, 980}, data->textures->button,
               "button_corner");
    button_add_action(data, "button_corner", &change_select_corner);
    button_add_text(data, "button_corner", "Select\nCorner");
    button_set_text_pos(data, "button_corner", (sfVector2f) {9, 15}, 1);
    button_add_text_box(data, "button_corner", data->textures->help_box,
                        (sfVector2f) {4, 1});
    button_add_text_box_message(data, "button_corner", "Select corner");
    button_help_display(data, "button_corner", (sfVector2i) {0, 1});
    button_set_tag(data, "button_corner", B_GAME);
}

void load_more_button(data_game *data)
{
    add_button(data, (sfVector2f) {1375, 980}, data->textures->button,
               "button_tile");
    button_add_action(data, "button_tile", &change_select_tile);
    button_add_text(data, "button_tile", "Select\nTile");
    button_set_text_pos(data, "button_tile", (sfVector2f) {9, 15}, 1);
    button_add_text_box(data, "button_tile", data->textures->help_box,
                        (sfVector2f) {5, 1});
    button_add_text_box_message(data, "button_tile", "Select one tile");
    button_help_display(data, "button_tile", (sfVector2i) {0, 1});
    button_set_tag(data, "button_tile", B_GAME);
    add_button(data, (sfVector2f) {10, 980}, data->textures->button,
               "button_up-down");
    button_add_action(data, "button_up-down", &change_dir);
    button_add_text(data, "button_up-down", "Up");
    button_set_text_pos(data, "button_up-down", (sfVector2f) {15, 30}, 1);
    button_add_text_box(data, "button_up-down", data->textures->help_box,
                        (sfVector2f) {10, 1});
    button_add_text_box_message(data, "button_up-down",
                                "Set your modification to up or down");
    button_help_display(data, "button_up-down", (sfVector2i) {-1, 0});
    button_set_tag(data, "button_up-down", B_GAME);
}

void load_last_button(data_game *data)
{
    add_button(data, (sfVector2f) {10, 10}, data->textures->button,
               "button_menu");
    button_add_action(data, "button_menu", &set_menu);
    button_add_text(data, "button_menu", "Menu");
    button_set_text_pos(data, "button_menu", (sfVector2f) {15, 30}, 1);
    button_add_text_box(data, "button_menu", data->textures->help_box,
                        (sfVector2f) {4, 1});
    button_add_text_box_message(data, "button_menu", "Pause menu");
    button_help_display(data, "button_menu", (sfVector2i) {-1, 0});
    button_set_tag(data, "button_menu", B_GAME);
    add_button(data, (sfVector2f) {1800, 140}, data->textures->button,
               "button_paint");
    button_add_action(data, "button_paint", NULL);
    button_add_text(data, "button_paint", "Paint");
    button_set_text_pos(data, "button_paint", (sfVector2f) {15, 30}, 1);
    button_add_text_box(data, "button_paint", data->textures->help_box,
                        (sfVector2f) {5, 1});
    button_add_text_box_message(data, "button_paint",
                                "Paint your \nmap(coming soon)");
    button_help_display(data, "button_paint", (sfVector2i) {1, 0});
    button_set_tag(data, "button_paint", B_GAME);
}

void load_slider(data_game *data)
{
    add_slider(data, "slider_effect", (sfVector2f) {1600, 1030});
    slider_set_slider_texture(data, "slider_effect", data->textures->slider, 1);
    slider_set_cursor_texture(data, "slider_effect", data->textures->button, 1);
    slider_set_extreme_value(data, "slider_effect", -5, 15);
    slider_set_cursor_position(data, "slider_effect", -20);
}

void load_button(data_game *data)
{
    load_some_button(data);
    load_more_button(data);
    load_last_button(data);
    set_hover_tex(data);
    load_slider(data);
    add_button(data, (sfVector2f)
                       {data->winsize_f.x - 100, data->winsize_f.y - 100},
               data->textures->button,
               "button_save");
    button_add_action(data, "button_save", &save_map);
    button_add_text(data, "button_save", "Save");
    button_set_text_pos(data, "button_save", (sfVector2f) {15, 30}, 1);
    button_add_text_box(data, "button_save", data->textures->help_box,
                        (sfVector2f) {4, 1});
    button_add_text_box_message(data, "button_save", "Save map");
    button_help_display(data, "button_save", (sfVector2i) {-1, 0});
    button_set_tag(data, "button_save", B_GAME);
    button_set_other_tex(data, "button_save", data->textures->button_hover,
                         data->textures->button_press);
}
