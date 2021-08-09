/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** creature_2.c
*/

#include <stdlib.h>
#include <math.h>
#include "p_creature.h"
#include "istl/utility.h"
#include "resource_holder.h"

bool_t creature_moves(creature_t const *cr)
{
    if (cr == 0)
        return (FALSE);
    if (cr->velo.x == 0 && cr->velo.y == 0)
        return (FALSE);
    if (cr->mstate == CM_STAND)
        return (FALSE);
    return (TRUE);
}

void creature_set_tick_hover(creature_t *cr, uint_t value)
{
    if (cr == 0)
        return;
    cr->hovered = value;
}

void creature_set_sprite(creature_t *cr, sfSprite const *sprite)
{
    if (cr == 0)
        return;
    cr->sprite = (sprite == 0) ? 0 : sfSprite_copy(sprite);
}

void creature_deal_dmg(creature_t *creature, uint_t dmg)
{
    if (creature == 0)
        return;
    dmg = (dmg > creature->health) ? creature->health : dmg;
    creature->health -= dmg;
}

cstats_t creature_get_stats(creature_t const *creature)
{
    cstats_t stat;

    stat.defense = 10;
    return (stat);
}
