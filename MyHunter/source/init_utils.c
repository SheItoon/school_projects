/*
** EPITECH PROJECT, 2019
** init other things
** File description:
** s
*/

#include "my_hunter.h"

void init_utils(params_t *params)
{
    params->globalclock = sfClock_create();
    params->flag = sfFalse;
    params->value = 0;
    params->view2 = sfView_create();
    params->valuestr = malloc(sizeof(char));
}
