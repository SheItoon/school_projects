/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "private/p_decoration.h"

void decor_set_animation(decor_t *decor, animf_t *anim)
{
    if (decor == NULL)
        return;
    decor->anim = anim;
}

void decor_set_zoffset(decor_t *decor, float offset)
{
    if (decor == NULL)
        return;
    decor->z_offset = offset;
}
