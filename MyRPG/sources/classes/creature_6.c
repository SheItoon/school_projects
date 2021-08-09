/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.c
*/

#include <stdlib.h>
#include <math.h>
#include "gcontext.h"
#include "p_creature.h"
#include "csfml_toolbox.h"
#include "istl/utility.h"
#include "resource_holder.h"
#include "scene.h"

void creature_update_pos(creature_t *cr, sfTime delta)
{
    sfVector2f res;
    sfVector2f *point = 0;
    float as_sec = sfTime_asSeconds(delta);

    res = (sfVector2f) {cr->velo.x, cr->velo.y};
    V_MUL(res, as_sec);
    sfSprite_move(cr->sprite, res);
    if (cpoint_reached(cr)) {
        point = list_pull(cr->path, list_begin(cr->path));
        if (point != 0)
            free(point);
        point = it_data(list_begin(cr->path));
        res = sfSprite_getPosition(cr->sprite);
        if (point != 0) {
            res = (sfVector2f){point->x - res.x, point->y - res.y};
            creature_update_dir(cr, res);
        } else
            cr->velo = (sfVector2f){0, 0};
    }
}

sfFloatRect creature_getgbounds(void const *creature_p)
{
    creature_t const *creature = creature_p;
    sfFloatRect sbds = (sfFloatRect) {0, 0, 0, 0};
    sfFloatRect hitbox;

    if (creature == NULL)
        return (sbds);
    sbds = sfSprite_getGlobalBounds(creature->sprite);
    hitbox = sbds;
    hitbox.left = sbds.left;
    hitbox.top = sbds.top + (sbds.height - creature->height);
    return (hitbox);
}
