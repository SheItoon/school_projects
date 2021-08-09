/*
** EPITECH PROJECT, 2019
** even more
** File description:
** oh ye
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

void window_set(params_t *params)
{
    sfRenderWindow_setFramerateLimit(params->window, 60);
    sfView_setSize(params->view2,(sfVector2f){params->winsize.x,
                params->winsize.y});
    sfView_setViewport(params->view2, (sfFloatRect){0, 0, 1, 1});
    sfRenderWindow_setMouseCursorVisible(params->window, sfFalse);
    sfView_setCenter(params->view2,(sfVector2f){params->winsize.x/2,
                params->winsize.y/2});
}

void cursor_init(params_t *params)
{
    sfSprite_setTexture(params->cursor, params->cursortex, sfFalse);
    sfSprite_setPosition(params->cursor,(sfVector2f)
                         {sfMouse_getPositionRenderWindow(params->window)
                                 .x - 30, sfMouse_getPositionRenderWindow
                                 (params->window).y - 30});
}

void display_all(params_t *params)
{
    sfRenderWindow_drawSprite(params->window, params->skyrim, NULL);
    sfRenderWindow_drawSprite(params->window, params->shrek, NULL);
    sfRenderWindow_drawSprite(params->window, params->tf2, NULL);
    sfRenderWindow_drawText(params->window, params->scoretext, NULL);
    sfRenderWindow_drawText(params->window, params->nbr, NULL);
    sfRenderWindow_drawText(params->window, params->goaltext, NULL);
    sfRenderWindow_drawSprite(params->window, params->pris.obeamos, NULL);
    sfRenderWindow_drawSprite(params->window, params->obamagod, NULL);
    sfRenderWindow_drawSprite(params->window, params->weap.bow, NULL);
    sfRenderWindow_drawSprite(params->window, params->cursor, NULL);
    sfRenderWindow_display(params->window);
}

void clear_n_set(params_t *params)
{
    sfRenderWindow_clear(params->window, sfColor_fromRGB(97, 207, 230));
    sfRenderWindow_setView(params->window, params->view2);

    if (params->value >= params->goal) {
        params->goal *= 2;
        params->lvl++;
        init_goal(params);
        if (params->lvl == HARD)
            sfView_rotate(params->view2, 90);
        if (params->lvl == WHAT)
            sfView_zoom(params->view2, 2);
        if (params->lvl == HELL) {
            sfView_zoom(params->view2, 0.4);
            sfView_rotate(params->view2, -54);
        }
    }
    if (params->lvl >= HELL)
        params->lvl = SEMI;
    hp_init(params,0);
}

void hunter(params_t *params)
{
    clear_n_set(params);
    draw_all(params);
    display_all(params);
}
