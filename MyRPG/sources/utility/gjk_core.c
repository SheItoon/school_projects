/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** gjk.c
*/
#include "istl/utility.h"
#include "csfml_toolbox.h"
#include "gjk.h"
#include "istl/common_types.h"

sfVector2f gjk_support(varray_t *shape, sfVector2f dir)
{
    uint_t count = sfVertexArray_getVertexCount(shape);
    sfVertex const *vr = 0;
    sfVector2f mv;
    double mdot = 0;
    double tmp = 0;

    vr = sfVertexArray_getVertex(shape, 0);
    mv = vr->position;
    mdot = V_DOT(dir, vr->position);
    for (uint_t i = 1; i < count; i++) {
        vr = sfVertexArray_getVertex(shape, i);
        tmp = V_DOT(dir, vr->position);
        if (tmp > mdot) {
            mv = vr->position;
            mdot = tmp;
        }
    }
    return (mv);
}
