/*
** EPITECH PROJECT, 2019
** there is another
** File description:
** normeeeeeeeed
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_hunter.h"
#include <time.h>

void hit(params_t *params)
{
    sfFloatRect prismpos = sfSprite_getGlobalBounds(params->pris.obeamos);
    sfFloatRect hedronpos = sfSprite_getGlobalBounds(params->obamagod);
    sfVector2i mousepos = sfMouse_getPositionRenderWindow(params->window);

    if (sfFloatRect_contains(&prismpos, mousepos.x, mousepos.y) &&
        (params->event.mouseButton.button == sfMouseLeft)) {
        sfSprite_setPosition(params->pris.obeamos, (sfVector2f)
                             {0,randomizer(1080 - 128)});
        params->value += 400 * params->multi;
    } else if (sfFloatRect_contains(&hedronpos, mousepos.x, mousepos.y) &&
               (params->event.mouseButton.button == sfMouseLeft)) {
        sfSprite_setPosition(params->obamagod, (sfVector2f)
                             {0,randomizer(1080 - 128)});
        params->value += 100 * params->multi;
    } else
        hp_init(params, 1);
}

void bow_init(params_t *params)
{
    sfSprite_setTextureRect(params->weap.bow, params->weap.recbow);
    sfSprite_setTexture(params->weap.bow, params->weap.bowtex, sfFalse);
    sfSprite_setPosition(params->weap.bow, (sfVector2f){params->winsize.x*0.785,0});
}

void window_event(params_t *params)
{
    while (sfRenderWindow_pollEvent(params->window, &params->event)) {
        switch (params->event.type) {
        case sfEvtClosed :
            sfRenderWindow_close(params->window);
            params->now = ENDGAME;
            break;
        default : break;
        }
        if ((params->event.mouseButton.button == sfMouseLeft) &&
            (sfMouse_isButtonPressed(sfMouseLeft))) {
            case_one(params);
        }
        if ((params->event.mouseButton.button == sfMouseLeft) &&
            (params->event.type == sfEvtMouseButtonReleased)) {
            case_second(params);
        }
    }
    //init_goal(params);
    params->valuestr = get_score(params->value);
    sfText_setString(params->nbr, params->valuestr);
}

void create_mywindow(int width, int height, char *name, params_t *params)
{
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 72;
    params->window = sfRenderWindow_create(video_mode, name, sfResize |
                                           sfClose, NULL);
}
