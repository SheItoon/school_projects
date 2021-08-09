/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** csfml_meta.c
*/

#include "csfml_meta.h"

void sfcshape_pdestroy(void *data)
{
    if (data == 0)
        return;
    sfCircleShape_destroy(data);
}

void sfvarray_pdestroy(void *data)
{
    if (data == 0)
        return;
    sfVertexArray_destroy(data);
}

void sfxshape_pdestroy(void *data)
{
    if (data == 0)
        return;
    sfConvexShape_destroy(data);
}

void *sffont_pcopy(void const *data)
{
    sfFont const *font = data;

    if (data == 0)
        return (0);
    return (sfFont_copy(font));
}

void sffont_pdestroy(void *data)
{
    sfFont *font = data;

    if (data == 0)
        return;
    sfFont_destroy(font);
}
