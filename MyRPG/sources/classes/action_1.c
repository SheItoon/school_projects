/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** action_1.c
*/

#include "gcontext.h"
#include "istl/utility.h"

const meta_bundle_t MB_ACTION = {
    action_copy,
    action_destroy,
    sizeof(action_t)
};

action_t *action_create(callback_t cb)
{
    action_t *act = malloc(sizeof(action_t));

    act->function = cb;
    return (act);
}

void *action_copy(void const *data)
{
    action_t *nact = 0;

    if (data == 0)
        return (0);
    nact = malloc(sizeof(action_t));
    *nact = *(action_t *)data;
    return (nact);
}

void action_destroy(void *data)
{
    action_t *act = (action_t *)data;

    if (data == 0)
        return;
    free(act);
}

