/*
** EPITECH PROJECT, 2019
** stocking more function
** File description:
** oof
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

void hunter_init(void *not_params)
{
    time_t t;
    params_t *params = (params_t *) not_params;

    srand((unsigned)time(&t));
    params_init(params);
}

void the_game(params_t *params)
{
    sfMusic_setLoop(params->music, sfTrue);
    sfMusic_play(params->music);
    sfMusic_setVolume(params->music, 25);
    params->level = 1;
    while (sfRenderWindow_isOpen(params->window))
        hunter(params);
}

int norminator(void)
{
    params_t *params = malloc(sizeof(params_t));

    params->thread_init = sfThread_create(&hunter_init, params);
    params->lock = sfMutex_create();
    prepare_loading(params);
    params->now = START;
    params->goal = 1000;
    init_goal(params);
    sfThread_launch(params->thread_init);
    while (params->now != ENDGAME && params->now != ENDLOAD) {
        if (params->now == GAMING)
            the_game(params);
        else if (params->now == LOADING)
            screensaving(params);
    }
    if (params->now == ENDGAME)
        goumed(params);
    else
        sfThread_terminate(params->thread_init);
    free(params);
    return (0);
}
