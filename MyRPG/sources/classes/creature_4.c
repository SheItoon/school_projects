/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** creature_basic.c
*/
#include <stdlib.h>
#include <math.h>
#include "p_creature.h"
#include "csfml_toolbox.h"
#include "istl/utility.h"
#include "resource_holder.h"

const meta_bundle_t MB_CREATURE = {
    creature_copy,
    creature_destroy,
    sizeof(creature_t)
};

creature_t *creature_create(uint_t health, double speed)
{
    creature_t *cr = 0;
    static utype_t created = (utype_t){0};

    if (speed < 0)
        return (0);
    cr = malloc(sizeof(creature_t));
    cr->mstate = CM_STAND;
    cr->in_state = sfTime_Zero;
    cr->health = health;
    cr->speed = speed;
    cr->velo = (sfVector2f){0, 0};
    cr->sprite = 0;
    cr->states = get_default_rstates();
    cr->path = list_create(MB_SFVEC);
    cr->subscribers = list_create(MB_PTR);
    cr->height = 233;
    created.i_num += 1;
    utility_set_var("creature_created", created);
    return (cr);
}

void *creature_copy(void const *data)
{
    creature_t const *creature = (creature_t *)data;
    creature_t *ncr = 0;

    if (data == 0)
        return (0);
    ncr = creature_create(creature->health, creature->speed);
    if (ncr == 0)
        return (0);
    ncr->velo = creature->velo;
    ncr->sprite = sfSprite_copy(creature->sprite);
    ncr->path = list_create(MB_SFVEC);
    return (ncr);
}

void creature_destroy(void *data)
{
    creature_t *creature = (creature_t *)data;

    if (data == 0)
        return;
    creature_free(&creature);
}

void creature_free(creature_t **pcreature)
{
    creature_t *cr = (pcreature == 0) ? 0 : (*pcreature);
    static utype_t destr = (utype_t){0};

    if (pcreature == 0 || cr == 0)
        return;
    if (cr->sprite != 0)
        sfSprite_destroy(cr->sprite);
    list_free(&cr->path);
    list_free(&cr->subscribers);
    free(cr);
    *pcreature = 0;
    destr.i_num += 1;
    utility_set_var("creature_destroyed", destr);
}

void creature_subscribe(creature_t *cr, tower_t *tower)
{
    if (cr == 0 || tower == 0)
        return;
    list_push_back(cr->subscribers, &tower);
}
