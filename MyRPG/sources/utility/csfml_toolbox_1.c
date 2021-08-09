/*
** EPITECH PROJECT, 2019
** Title
** File description:
** Description
*/

#include "csfml_toolbox.h"
#include <stdlib.h>

sfRenderStates get_default_rstates(void)
{
    sfRenderStates states = {
        sfBlendAlpha,
        sfTransform_Identity,
        0,
        0
    };

    return (states);
}

bool_t sfTime_gt(sfTime lhs, sfTime rhs)
{
    sfInt64 t1 = sfTime_asMicroseconds(lhs);
    sfInt64 t2 = sfTime_asMicroseconds(rhs);

    return (t1 > t2);
}

sfTime sfTime_sub(sfTime lhs, sfTime rhs)
{
    float t1 = sfTime_asSeconds(lhs);
    float t2 = sfTime_asSeconds(rhs);
    float tmp;

    tmp = (t2 > t1) ? t2 - t1 : t1 - t2;
    sfTime res = sfSeconds(tmp);
    return (res);
}

sfTime sfTime_add(sfTime lhs, sfTime rhs)
{
    float t1 = sfTime_asSeconds(lhs);
    float t2 = sfTime_asSeconds(rhs);

    sfTime res = sfSeconds(t1 + t2);
    return (res);
}
