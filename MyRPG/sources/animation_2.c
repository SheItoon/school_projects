/*
** EPITECH PROJECT, 2020
** defender
** File description:
** second file for animation
*/

#include <stdlib.h>
#include <math.h>
#include "istl/utility.h"
#include "animation.h"

void animf_destroy(void *data)
{
    animf_t *anim = (animf_t *)data;

    list_free(&anim->frames);
    free(anim);
}

void animf_push_frame(animf_t *anim, sfIntRect frame)
{
    if (anim == 0)
        return;
    list_push_back(anim->frames, &frame);
}
