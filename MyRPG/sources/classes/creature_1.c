/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** creature.c
*/

#include <stdlib.h>
#include <math.h>
#include "p_creature.h"
#include "istl/utility.h"
#include "resource_holder.h"
#include "scene.h"

void creature_move_at(creature_t *cr, sfVector2f pos)
{
    sfVector2f cpos;
    bool_t vnull = TRUE;

    if (cr == 0 || cr->sprite == 0)
        return;
    vnull = (cr->velo.x == 0 && cr->velo.y == 0) ? vnull : FALSE;
    if (list_len(cr->path) == 0 && vnull) {
        cpos = sfSprite_getPosition(cr->sprite);
        cpos = (sfVector2f) {pos.x - cpos.x, pos.y - cpos.y};
        creature_update_dir(cr, cpos);
    }
    list_push_back(cr->path, &pos);
}

void notify_subs(list_t *subs)
{
    iterator_t it;

    if (subs == 0)
        return;
}

void creature_update(void *cr_p, sfTime delta, scene_t *scene)
{
    creature_t *cr = cr_p;

    if (cr == 0)
        return;
    if (cr->sprite != 0)
        creature_update_pos(cr, delta);
    if (cr->health <= 0) {
        notify_subs(cr->subscribers);
        scene_unlink(scene, RO_CREATURE, cr);
        return;
    }
    creature_update_state(cr, delta);
    creature_update_anim(cr);
}

void creature_draw(
        sfRenderWindow *window,
        void const *cr_p,
        sfRenderStates const *st)
{
    creature_t const *cr = cr_p;

    if (window == 0 || cr == 0 || cr->sprite == 0)
        return;
    sfRenderWindow_drawSprite(window, cr->sprite, st);
}
