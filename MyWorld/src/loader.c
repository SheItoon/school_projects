/*
** EPITECH PROJECT, 2020
** loader
** File description:
** loader
*/

#include "my_world.h"

void drawer(data_game *data)
{
    sfRenderWindow_drawSprite(data->window,
    data->loader.background, NULL);
    sfRenderWindow_drawSprite(data->window,
    data->loader.ground, NULL);
    sfRenderWindow_drawSprite(data->window,
    data->loader.loading, NULL);
    sfRenderWindow_drawSprite(data->window,
    data->loader.textloading, NULL);
    sfRenderWindow_drawSprite(data->window,
    data->loader.scared, NULL);
    sfRenderWindow_drawPrimitives(data->window,
    data->loader.percent.vertices, 4, sfQuads, NULL);
    if (data->loader.ready)
        sfRenderWindow_drawText(data->window, data->loader.text, NULL);
    sfRenderWindow_display(data->window);
}

void update_score(data_game *data)
{
    float actual = ((float)data->loader.toload * 100 /
            (float)data->loader.loaded) * 5;

    data->loader.percent.vertices[1].position =
    (sfVector2f){(float)data->window_size.x /2 - 246 + actual,
                 (float)data->window_size.y / 4 + (33 * 4)};
    data->loader.percent.vertices[2].position =
    (sfVector2f){(float)data->window_size.x /2 - 246 + actual,
                 (float)data->window_size.y / 4 + (33 * 3)};
}

void update_rect(data_game *data)
{
    data->loader.loadrect.left += 31;
    if (data->loader.loadrect.left >= 269)
        data->loader.loadrect.left = 148;
    data->loader.textrect.left += 128;
    if (data->loader.textrect.left >= 512)
        data->loader.textrect.left = 0;
    data->loader.scaredrec.left += 16;
    if (data->loader.scaredrec.left >= 496)
        data->loader.scaredrec.left = 417;
}

void anim_loading(data_game *data)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(100));
    float time = sfTime_asMilliseconds(
    sfClock_getElapsedTime(data->sys.clock));
    static float pastime = 0;
    float elapsed = time - pastime;

    if (elapsed > interval) {
        update_score(data);
        update_rect(data);
        move_sprite(data);
        pastime = time;
    }
    sfSprite_setTextureRect(data->loader.scared, data->loader.scaredrec);
    sfSprite_setTextureRect(data->loader.loading, data->loader.loadrect);
    sfSprite_setTextureRect(data->loader.textloading, data->loader.textrect);
}

void loader(data_game *data)
{
    sfEvent event;

    while (sfRenderWindow_isOpen(data->window) &&
    data->state == LOADING) {
        while (sfRenderWindow_pollEvent(data->window,
        &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(data->window);
                data->state = ENDLOAD;
            }
            if (event.type == sfEvtKeyPressed && data->loader.ready)
                data->state = MENU;
        }
        sfRenderWindow_clear(data->window, sfWhite);
        anim_loading(data);
        drawer(data);
    }
}
