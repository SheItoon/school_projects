/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** modh_creature_hover.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "standard_session.h"
#include "creature.h"
#include "cevent.h"

static int handler_core(mdevent_t evt)
{
    creature_t *cr = evt.creature_hovered.ptr;

    creature_set_tick_hover(cr, 5);
    return (0);
}

int modh_creature_hover(void *evt_p, gcontext_t *ctx)
{
    mdevent_t evt;

    evt = *(mdevent_t *)evt_p;
    return (handler_core(evt));
}
