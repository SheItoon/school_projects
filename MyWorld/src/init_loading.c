/*
** EPITECH PROJECT, 2020
** init loading
** File description:
** init
*/

#include "my_world.h"
#include "struct.h"
#include "loader.h"

void set_posinit(data_game *data)
{
    sfSprite_setPosition(data->loader.loading,
                         (sfVector2f) {(float) data->window_size.x / 2 - 150,
                                       (float) data->window_size.y / 2 -
                                       (33 * 3)});
    sfSprite_setPosition(data->loader.textloading,
                         (sfVector2f) {(float) data->window_size.x / 2 - 256,
                                       (float) data->window_size.y / 4 -
                                       (33 * 2)});
    sfSprite_setPosition(data->loader.scared,
                         (sfVector2f) {(float) data->window_size.x / 2 + 150,
                                       (float) data->window_size.y / 2 - 21});
    sfText_setPosition(data->loader.text,
                       (sfVector2f) {(float) data->window_size.x / 2 - 128,
                                     (float) data->window_size.y / 4 + (40)});
    sfSprite_setPosition(data->loader.ground,
                         (sfVector2f) {0 - (16 * 120),
                                       (float) data->window_size.y / 2 +
                                       (33 * 4)});
    sfText_setString(data->loader.text, "Press any key to continue");
    sfText_setColor(data->loader.text, sfBlack);
    sfText_setCharacterSize(data->loader.text, 50);
}

void load_sprite(data_game *data)
{
    data->loader.loading = sfSprite_create();
    data->loader.loadtex = sfTexture_createFromFile
            ("rsc/dungeontexturesheet.png", NULL);
    sfSprite_setTexture(data->loader.loading, data->loader.loadtex,
                        sfFalse);
    data->loader.loadrect = (sfIntRect) {148, 271, 31, 33};
    sfSprite_setTextureRect(data->loader.loading, data->loader.loadrect);
    sfSprite_setScale(data->loader.loading, (sfVector2f) {7, 7});
    data->loader.background = sfSprite_create();
    data->textures->font = sfTexture_createFromFile("./rsc/back.png", NULL);
    sfSprite_setTexture(data->loader.background, data->textures->font,
                        sfFalse);
    sfSprite_setScale(data->loader.background, (sfVector2f) {7, 4.5f});
    data->loader.ground = sfSprite_create();
    data->loader.textloading = sfSprite_create();
    data->loader.textloadtex = sfTexture_createFromFile("rsc/loading",
                                                        NULL);
    data->loader.font = sfFont_createFromFile("rsc/loading.ttf");
    data->loader.text = sfText_create();
    sfText_setFont(data->loader.text, data->loader.font);
}

void init_percent(data_game *data)
{
    data->loader.percent.vertices = malloc(sizeof(sfVertex) * 4);
    for (int i = 0; i < 4; i++) {
        data->loader.percent.vertices[i].color = sfGreen;
        if (i > 1)
            data->loader.percent.vertices[i].position =
                    (sfVector2f) {(float) data->window_size.x / 2 - 246,
                                  (float) data->window_size.y / 4 + (33 * 3)};
        else
            data->loader.percent.vertices[i].position =
                    (sfVector2f) {(float) data->window_size.x / 2 - 246,
                                  (float) data->window_size.y / 4 + (33 * 4)};
    }
}

void init_loading(data_game *data)
{
    data->textures = malloc(sizeof(texture_t));
    load_sprite(data);
    data->loader.ground_tex = sfTexture_createFromFile("rsc/tile_set.png",
                                                       NULL);
    sfSprite_setTexture(data->loader.ground, data->loader.ground_tex, sfFalse);
    sfSprite_setTextureRect(data->loader.ground, (sfIntRect) {0, 0, 32, 16});
    data->loader.textrect = (sfIntRect) {0, 0, 128, 34};
    sfSprite_setTexture(data->loader.textloading, data->loader.textloadtex,
                        sfFalse);
    sfSprite_setTextureRect(data->loader.textloading,
                            data->loader.textrect);
    sfSprite_setScale(data->loader.textloading, (sfVector2f) {4, 4});
    data->loader.scared = sfSprite_create();
    sfSprite_setTexture(data->loader.scared, data->loader.loadtex, sfFalse);
    data->loader.scaredrec = (sfIntRect) {417, 329, 16, 23};
    sfSprite_setTextureRect(data->loader.scared, data->loader.scaredrec);
    sfSprite_setScale(data->loader.scared, (sfVector2f) {7, 7});
    init_percent(data);
    set_posinit(data);
    sfSprite_setScale(data->loader.ground, (sfVector2f) {120, 33.75f});
}

void move_sprite(data_game *data)
{
    sfSprite_move(data->loader.loading, (sfVector2f) {40, 0});
    if (sfSprite_getPosition(data->loader.loading).x >=
        (float) data->window_size.x) {
        sfSprite_setPosition(data->loader.loading,
                             (sfVector2f) {-400,
                                           (float) data->window_size.y / 2 -
                                           (33 * 3)});
        swap_mobload(data, 0);
    }
    sfSprite_move(data->loader.scared, (sfVector2f) {40, 0});
    if (sfSprite_getPosition(data->loader.scared).x >=
        (float) data->window_size.x) {
        sfSprite_setPosition(data->loader.scared,
                             (sfVector2f) {-400,
                                           (float) data->window_size.y / 2 -
                                           30});
        swap_mobload(data, 1);
    }
}
