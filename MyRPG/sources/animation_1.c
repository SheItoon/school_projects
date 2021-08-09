/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** animation.c
*/

#include <stdlib.h>
#include <math.h>
#include "csfml_toolbox.h"
#include "istl/utility.h"
#include "animation.h"

const meta_bundle_t MB_ANIMATION = {
    animf_copy,
    animf_destroy,
    sizeof(animf_t)
};

animf_t *animf_create(sfTime dur, point_set_t cprof)
{
    animf_t *anim = malloc(sizeof(animf_t));

    anim->duration = dur;
    anim->cprofile = cprof;
    anim->looped = TRUE;
    anim->direction = TRUE;
    anim->fill = FORWARDS;
    anim->frames = list_create(MB_IRECT);
    return (anim);
}

void animf_free(animf_t **anim)
{
    if (anim == 0 || *anim == 0)
        return;
    list_free(&(*anim)->frames);
    *anim = 0;
}

void *animf_copy(void const *data)
{
    animf_t const *anim = (animf_t const *)data;
    animf_t *cpy = animf_create(anim->duration, anim->cprofile);

    cpy->frames = list_copy(anim->frames);
    cpy->looped = anim->looped;
    cpy->fill = anim->fill;
    cpy->direction = anim->direction;
    return (cpy);
}

static uint_t calc_frame_index(animf_t *anim, sfTime in_state)
{
    double tmp;
    uint_t fcount = list_len(anim->frames);

    tmp = sfTime_asSeconds(in_state) / sfTime_asSeconds(anim->duration);
    tmp = cubic_bezier(anim->cprofile, tmp) * fcount;
    return (floor(tmp));
}

sfIntRect *animf_get_frame(animf_t *anim, sfTime in_state)
{
    uint_t index;
    double tmp;
    iterator_t it;

    if (anim == 0)
        return (0);
    if (anim->looped)
        T_MOD(in_state, anim->duration);
    else if (sfTime_gt(in_state, anim->duration))
        return (0);
    if (!anim->direction)
        in_state = sfSeconds(1 - sfTime_asSeconds(in_state));
    index = calc_frame_index(anim, in_state);
    it = list_begin(anim->frames);
    for (uint_t i = 0; !list_final(anim->frames, it) && i < index; i++)
        it = it_next(it);
    return (list_final(anim->frames, it) ? 0 : (sfIntRect*)list_data(it));
}
