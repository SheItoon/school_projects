/*
** EPITECH PROJECT, 2019
** cases and stuff
** File description:
** stuf
*/

#include "my_hunter.h"

void case_second(params_t *params)
{
    hit(params);
    params->flag = sfFalse;
    params->weap.recbow.left = 0;
    sfSound_stop(params->chargebow);
    sfMusic_setVolume(params->music, 25);
}

void case_one(params_t *params)
{
    params->flag = sfTrue;
    sfSound_setVolume(params->chargebow, 100);
    sfMusic_setVolume(params->music, 3);
    sfSound_play(params->chargebow);
}
