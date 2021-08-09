/*
** EPITECH PROJECT, 2019
** drawing function
** File description:
** o
*/

#include "my_hunter.h"

void shrek(params_t *params)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(130));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    sfSprite_setTexture(params->shrek, params->shrektex, sfFalse);
    sfSprite_setTextureRect(params->shrek, params->shrekrec);
    if (elapsed > interval) {
        params->shrekrec.top += 60;
        if (params->shrekrec.top >= 13680) {
            params->shrekrec.top = 0;
            params->shrekrec.left += 60;
            if (params->shrekrec.left >= 13980)
                params->shrekrec.left = 0;
        }
        pastime = time;
    }
    sfSprite_setPosition(params->shrek,(sfVector2f){0, 0});
    sfSprite_setScale(params->shrek, (sfVector2f){2, 2});
}

void skyriom(params_t *params)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(70));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    sfSprite_setTexture(params->skyrim, params->awake, sfFalse);
    sfSprite_setTextureRect(params->skyrim, params->finallyy);
    if (elapsed > interval) {
        params->finallyy.top += 360;
        if (params->finallyy.left >= 12800 && params->finallyy.top >= 3960) {
            params->finallyy.top = 0;
            params->finallyy.left = 0;
        } else if (params->finallyy.top >= 11160) {
            params->finallyy.top = 0;
            params->finallyy.left += 640;
            if (params->finallyy.left >= 13440)
                params->finallyy.left = 0;
        }
        pastime = time;
    }
    sfSprite_setPosition(params->skyrim,(sfVector2f){0, 0});
    sfSprite_setScale(params->skyrim, (sfVector2f){3, 3});
}

void hp_init(params_t *params, int check)
{
    if (check) {
        params->tf2rec.left += 150;
        if (params->tf2rec.left >= 1500) {
            sfRenderWindow_close(params->window);
            params->now = ENDGAME;
        }
        sfSprite_setTexture(params->tf2, params->tf2tex, sfFalse);
        sfSprite_setTextureRect(params->tf2, params->tf2rec);
    } else {
        sfSprite_setTexture(params->tf2, params->tf2tex, sfFalse);
    }
}

void draw_all(params_t *params)
{
    window_event(params);
    skyriom(params);
    anim_prism(params);
    obama_care(params);
    anim_prism2(params);
    obama_care2(params);
    if (params->flag)
        anim_bow(params);
    bow_init(params);
    cursor_init(params);
    shrek(params);
}
