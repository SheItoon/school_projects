/*
** EPITECH PROJECT, 2019
** loading_game.c
** File description:
** load all resources for the game
*/

#include "my_world.h"

void load_texture(data_game *data)
{
    data->textures->snow = sfTexture_createFromFile("./rsc/snow.png", NULL);
    data->textures->stone = sfTexture_createFromFile("./rsc/stone.png", NULL);
    data->textures->dirt = sfTexture_createFromFile("./rsc/dirt.png", NULL);
    data->textures->grass = sfTexture_createFromFile("./rsc/grass.png", NULL);
    data->loader.toload += 4;
    data->textures->button = sfTexture_createFromFile("./rsc/button.png", NULL);
    data->textures->slider = sfTexture_createFromFile("./rsc/slider.png", NULL);
    data->textures->button_hover = sfTexture_createFromFile(
            "./rsc/button_hover.png", NULL);
    data->textures->button_press = sfTexture_createFromFile(
            "./rsc/button_press.png", NULL);
    data->loader.toload += 4;
    data->textures->help_box = sfTexture_createFromFile(
            "./rsc/help_box.png", NULL);
    data->textures->button_l = sfTexture_createFromFile("./rsc/button_l.png",
                                                        NULL);
    data->textures->button_hover_l = sfTexture_createFromFile(
            "./rsc/button_l_hover.png", NULL);
    data->textures->button_press_l = sfTexture_createFromFile(
            "./rsc/button_l_press.png", NULL);
    data->loader.toload += 4;
}

void load_game_sprite(data_game *data)
{
    sfVector2f scale = {7, 4.5f};

    data->font = sfFont_createFromFile("rsc/font.ttf");
    data->loader.toload++;
    data->sprites->font = sfSprite_create();
    data->loader.toload++;
    sfSprite_setTexture(data->sprites->font, data->textures->font, sfFalse);
    sfSprite_setScale(data->sprites->font, scale);
    data->textures->help = sfTexture_createFromFile("./rsc/help.png", NULL);
    data->loader.toload++;
    data->sprites->help = sfSprite_create();
    data->loader.toload++;
    sfSprite_setTexture(data->sprites->help, data->textures->help, sfFalse);
    sfSprite_setScale(data->sprites->help, (sfVector2f){1, 1});
}

void load_interface(data_game *data)
{
    load_texture(data);
    load_game_sprite(data);
    load_button(data);
}
