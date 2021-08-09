/*
** EPITECH PROJECT, 2019
** my hunter
** File description:
** duck hunt like game
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_hunter.h"
#include <time.h>
#include <unistd.h>

void destroy_last(params_t *params)
{
    sfSoundBuffer_destroy(params->chargebuff);
    sfMusic_destroy(params->music);
    sfHttp_destroy(params->http);
    sfSprite_destroy(params->skyrim);
    sfTexture_destroy(params->awake);
    sfHttpRequest_destroy(params->request);
    for (int i = 0; i < 7; i++)
        sfHttpResponse_destroy(params->response[i]);
    free(params->response);
    sfThread_destroy(params->thread_init);
}

void goumed(params_t *params)
{
    sfRenderWindow_destroy(params->window);
    sfSprite_destroy(params->pris.obeamos);
    sfSprite_destroy(params->obamagod);
    sfTexture_destroy(params->pris.obama);
    sfTexture_destroy(params->obeeanus);
    sfClock_destroy(params->globalclock);
    sfSprite_destroy(params->weap.bow);
    sfView_destroy(params->view2);
    sfFont_destroy(params->score);
    sfText_destroy(params->scoretext);
    sfTexture_destroy(params->weap.bowtex);
    sfTexture_destroy(params->shrektex);
    sfSprite_destroy(params->shrek);
    sfSprite_destroy(params->tf2);
    sfTexture_destroy(params->tf2tex);
    sfFont_destroy(params->nbfont);
    sfText_destroy(params->nbr);
    sfTexture_destroy(params->cursortex);
    sfSprite_destroy(params->cursor);
    sfSound_destroy(params->chargebow);
    destroy_last(params);
}

void params_init(params_t *params)
{
    sfMutex_lock(params->lock);
    params->now = LOADING;
    init_web(params);
    init_text(params);
    init_last_text(params);
    init_skyrim_n_loading(params);
    init_sprite(params);
    init_rect(params);
    init_score(params);
    init_audio(params);
    params->now = GAMING;
    sfMutex_unlock(params->lock);
}

void show_help(void)
{
    write(1, "Welcome to my online hunter !\nIn this game you will have to shoot\
 some entities but beware because missing them will result in losing life!\nRe\
ach 0 and you die simple right ?\nTheres only two way to end this game !\n\
Dying from missing too many shots or reaching the score goal :D\n\
Last thing ! If you dont want to play you can watch Shrek 1 the movie!\n\
Please dont launch with bad internet\n", 386);
}

int main(int ac, char **av)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h'))
        show_help();
    else if (ac != 0 && ac > 2)
        return (84);
    else
        return(norminator());
}
