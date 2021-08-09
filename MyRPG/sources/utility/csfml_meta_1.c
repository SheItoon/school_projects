/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.c
*/
#include "csfml_meta.h"

void sftext_pdestroy(void *data)
{
    sfText *txt = data;

    if (data == 0)
        return;
    sfText_destroy(txt);
}

void sfvarray_draw(
        sfRenderWindow *w,
        void const *varray_p,
        sfRenderStates const *st)
{
    sfRenderWindow_drawVertexArray(w, varray_p, st);
}

sfFloatRect sfvarray_getgbounds(void const *varray_p)
{
    sfVertexArray *cpy = sfVertexArray_copy(varray_p);
    sfFloatRect rect;

    rect = sfVertexArray_getBounds(cpy);
    sfVertexArray_destroy(cpy);
    return (rect);
}
