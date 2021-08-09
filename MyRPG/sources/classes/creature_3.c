/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/
#include <stdlib.h>
#include <math.h>
#include "p_creature.h"
#include "istl/utility.h"
#include "resource_holder.h"

sfVector2f creature_get_position(creature_t const *creature)
{
    sfVector2f vec = (sfVector2f){0, 0};
    sfVector2f pos = vec;
    sfFloatRect bds;

    if (creature == 0)
        return (vec);
    bds = creature_getgbounds(creature);
    pos = (sfVector2f) {bds.left, bds.top};
    vec = (sfVector2f) {bds.width / 2, 349};
    pos = (sfVector2f) {pos.x + vec.x, pos.y + vec.y};
    return (pos);
}

void creature_apply_effect(creature_t *creature, effect_tt effect)
{

}
