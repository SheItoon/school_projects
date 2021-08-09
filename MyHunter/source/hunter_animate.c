/*
** EPITECH PROJECT, 2019
** function holder file
** File description:
** how can i handle all these functions
*/
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_hunter.h"

void anim_prism2(params_t *params)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(12));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    if (elapsed > interval) {
        params->obarec.left += 128;
        if (params->obarec.left >= 7680)
            params->obarec.left = 0;
        pastime = time;
    }
}

void obama_care2(params_t *params)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(3));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    sfSprite_setTexture(params->obamagod, params->obeeanus, sfFalse);
    sfSprite_setTextureRect(params->obamagod, params->obarec);
    if (elapsed > interval) {
        sfSprite_move(params->obamagod, (sfVector2f){3,0});
        pastime = time;
    }
    if (sfSprite_getPosition(params->obamagod).x >= params->winsize.x)
        sfSprite_setPosition(params->obamagod,(sfVector2f){0,
                    randomizer(params->winsize.y - 128)});
    sfSprite_setScale(params->obamagod, (sfVector2f){0.5,0.5});
}

void anim_prism(params_t *params)
{
    float interval = sfTime_asMilliseconds(sfMilliseconds(30));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    if (elapsed > interval) {
        params->pris.obeam.left += 128;
        if (params->pris.obeam.left >= 6528)
            params->pris.obeam.left = 0;
        pastime = time;
    }
}

void anim_bow(params_t *params)
{
    float interval = sfTime_asSeconds(sfSeconds(0.6));
    float time = sfTime_asSeconds(sfClock_getElapsedTime
                                  (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    if (elapsed > interval) {
        switch (params->weap.recbow.left) {
        case 0 :params->weap.recbow.left += 414;
            params->multi = 0.5;
            break;
        case 414 :params->weap.recbow.left += 508;
            params->multi = 1;
            break;
        case 922 :params->weap.recbow.left += 616;
            params->multi = 1.5;
            break;
        case 1538 :params->weap.recbow.left = 1538;
            params->multi = 2;
            break;
        }
        pastime = time;
    }
}

void obama_care(params_t *params)
{
    sfVector2f position = {6,0};
    float interval = sfTime_asMilliseconds(sfMilliseconds(3));
    float time = sfTime_asMilliseconds(sfClock_getElapsedTime
                                       (params->globalclock));
    static float pastime = 0;
    float elapsed = time - pastime;

    sfSprite_setTexture(params->pris.obeamos, params->pris.obama, sfFalse);
    sfSprite_setTextureRect(params->pris.obeamos, params->pris.obeam);
    if (elapsed > interval) {
        sfSprite_move(params->pris.obeamos, position);
        pastime = time;
    }
    if (sfSprite_getPosition(params->pris.obeamos).x >= params->winsize.x)
        sfSprite_setPosition(params->pris.obeamos,(sfVector2f)
                             {0,randomizer(params->winsize.y - 128)});
    sfSprite_setScale(params->pris.obeamos, (sfVector2f){0.5,0.5});
}
